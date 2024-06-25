from typing import List

import pytest


class Col:
    def __init__(
        self,
        hit=0,
        new_x=0,
        new_y=0,
        dy=0,
        dx=0,
        nx=0,
        ny=0,
        col_id=0,
        dist=float("-inf"),
    ):
        self.hit = hit
        self.new_x = new_x
        self.new_y = new_y
        self.dy = dy
        self.dx = dx
        self.nx = nx
        self.ny = ny
        self.col_id = col_id
        self.dist = dist

    def __repr__(self):
        return (
            f"hit={self.hit}, new={self.new_x, self.new_y}, "
            f"delta={self.dx, self.dy}, norm={self.nx, self.ny}, "
            f"dist={self.dist} "
        )

def val_between(low, val, high):
    return (low <= val <= high)


def COL_rect_rect(a, b):
    col = Col()

    # edge cases first
    if (
        (a.vy < 0)
        and (a.y == b.y + b.h)
        and (
            val_between(b.x, a.x, b.x+b.w)
            or 
            val_between(b.x, a.x+b.w, b.x+b.w)
        )
    ):

        col.hit = 1
        col.ny = -1
        col.new_x = a.x + a.vx
        col.new_y = a.y
        col.dist = 0

        return col

    # determine ray beg
    rx = a.x + a.w / 2
    ry = a.y + a.h / 2

    # minkowski sum
    min_x = b.x - a.w / 2
    min_y = b.y - a.h / 2
    max_x = b.x + b.w + a.w / 2
    max_y = b.y + b.h + a.h / 2

    last_entry = float("-inf")
    first_exit = float("inf")

    if a.vx == -0 and a.vy == 0:
        # what now?
        pass

    # x collision
    if a.vx != 0:
        t1 = (min_x - rx) / a.vx
        t2 = (max_x - rx) / a.vx

        last_entry = max(last_entry, min(t1, t2))
        first_exit = min(first_exit, max(t1, t2))

    elif rx <= min_x or rx >= max_x:
        return col

    eps = 1e-10

    # y collision
    if a.vy != 0:

        t1 = (min_y - ry) / a.vy
        t2 = (max_y - ry) / a.vy

        last_entry = max(last_entry, min(t1, t2))
        first_exit = min(first_exit, max(t1, t2))

    elif ry <= min_y or ry >= max_y:
        return col

    # fill collision data
    if first_exit > last_entry and first_exit > 0 and last_entry < 1:
        col.hit = 1
        col.new_x = a.x + a.vx * last_entry
        col.new_y = a.y + a.vy * last_entry
        col.dist = last_entry

        hit_x = rx + a.vx * last_entry
        hit_y = ry + a.vy * last_entry

        col.dx = hit_x - (a.x + a.w / 2)
        col.dy = hit_y - (a.y + a.h / 2)

        px = b.w / 2 - abs(col.dx)
        py = b.h / 2 - abs(col.dy)

        if px < py:
            col.nx = (col.dx > 0) - (col.dx < 0)
        else:
            col.ny = (col.dy > 0) - (col.dy < 0)

    return col


class Ent:
    def __init__(self, x, y, w, h, vx, vy, _id=0):
        self.x = x
        self.y = y
        self.w = w
        self.h = h
        self.vx = vx
        self.vy = vy
        self.id = _id

    def __repr__(self):
        return f"pos={self.x, self.y}, hw={self.w, self.h}, " f"v={self.vx, self.vy}"


def resolve_col(entity, col):
    entity.y = round(col.new_y + 0.5)
    entity.x = round(col.new_x + 0.5)

    if col.nx != 0:
        entity.vx = 0

    elif col.ny != 0:
        entity.vy = 0

    return entity


def resolve_all_static_collision(main: Ent, colliders: List[Ent]):

    for c in colliders:

        # AABB aabb_minkowski_difference(AABB a, AABB b)
        rx = (c.x + c.w / 2) - (main.x + main.w / 2)
        ry = (c.y + c.h / 2) - (main.y + main.h / 2)

        rhx = c.w / 2 + main.w / 2
        rhy = c.h / 2 + main.h / 2

        min_x = rx - rhx - 1
        min_y = ry - rhy - 1
        max_x = rx + rhx + 1
        max_y = ry + rhy + 1

        if min_x <= 0 and max_x >= 0 and min_y <= 0 and max_y >= 0:
            # penetration vec function

            min_dist = abs(min_x)
            pen_x = min_x
            pen_y = 0

            if abs(max_x) < min_dist:
                min_dist = abs(max_x)
                pen_x = max_x

            if abs(min_y) < min_dist:
                min_dist = abs(min_y)
                pen_x = 0
                pen_y = min_y

            if abs(max_y) < min_dist:
                pen_x = 0
                pen_y = max_y

            main.x += pen_x
            main.y += pen_y

    return main


def resolve_all_collision(main: Ent, colliders: List[Ent]):
    col = Col()

    for c in colliders:
        cand = COL_rect_rect(main, c)

        if cand.hit and cand.dist > col.dist:
            col = cand

        elif cand.hit and cand.dist == col.dist:
            if abs(main.vx) > abs(main.vy) and (col.nx != 0):
                col = cand

            elif abs(main.vy) > abs(main.vx) and (col.ny != 0):
                col = cand

    resolved = resolve_col(main, col)

    return resolved, col


@pytest.mark.parametrize(
    "cols",
    [
        [Ent(100, 50, 32, 32, 0, 0, 13)],
        [Ent(20, 20, 79, 79, 0, 0, 13)],
        [Ent(20, 20, 10, 79, 0, 0, 13), Ent(40, 20, 10, 79, 0, 0, 13)],
        [Ent(20, 20, 10, 79, 0, 0, 13), Ent(40, 90, 10, 10, 0, 0, 13)],
    ],
)
def test_no_collision(cols):
    main = Ent(100, 100, 50, 32, 0, 0, 13)

    result, col = resolve_all_collision(main, cols)

    assert col.hit == 0
    assert result == main


@pytest.mark.parametrize(
    "main, cols",
    [
        (
            Ent(409, 600, 9, 20, 0, -1, 0),
            [
                Ent(377, 540, 32, 32, 0, 0, 0),
                Ent(400, 540, 32, 32, 0, 0, 0),
            ],
        ),
        (
            Ent(400, 600, 9, 20, 0, -1, 0),
            [
                Ent(377, 540, 32, 32, 0, 0, 0),
                Ent(400, 540, 32, 32, 0, 0, 0),
            ],
        ),
        (
            Ent(377, 600, 9, 20, 0, -1, 0),
            [
                Ent(377, 540, 32, 32, 0, 0, 0),
                Ent(400, 540, 32, 32, 0, 0, 0),
            ],
        ),
        (
            Ent(409, 600, 9, 20, 0, -6, 0),
            [
                Ent(377, 540, 32, 32, 0, 0, 0),
                Ent(400, 540, 32, 32, 0, 0, 0),
            ],
        ),
        (
            Ent(400, 600, 9, 20, 0, -6, 0),
            [
                Ent(377, 540, 32, 32, 0, 0, 0),
                Ent(400, 540, 32, 32, 0, 0, 0),
            ],
        ),
        (
            Ent(377, 600, 9, 20, 0, -6, 0),
            [
                Ent(377, 540, 32, 32, 0, 0, 0),
                Ent(400, 540, 32, 32, 0, 0, 0),
            ],
        ),
    ],
)
def test_collision_gravity_no_hit(main, cols):
    result, col = resolve_all_collision(main, cols)

    assert col.hit == 0
    assert result.y == round(col.new_y + 0.5)
    assert result.x == round(col.new_x + 0.5)
    assert result.vx == 0
    assert result.vy == main.vy


@pytest.mark.parametrize(
    "main, cols",
    [
        (
            Ent(398, 572, 9, 20, 0, -6, 0),
            [
                Ent(377, 540, 32, 32, 0, 0, 0),
                Ent(409, 540, 32, 32, 0, 0, 0),
            ],
        ),
        (
            Ent(400, 572, 9, 20, 0, -6, 0),
            [
                Ent(377, 540, 32, 32, 0, 0, 0),
                Ent(409, 540, 32, 32, 0, 0, 0),
            ],
        ),
        (
            Ent(409, 572, 9, 20, 0, -6, 0),
            [
                Ent(377, 540, 32, 32, 0, 0, 0),
                Ent(409, 540, 32, 32, 0, 0, 0),
            ],
        ),
        (
            Ent(400, 572.0, 9, 20, 0, -2, 0),
            [
                Ent(377, 540, 32, 32, 0, 0, 0),
                Ent(400, 540, 32, 32, 0, 0, 0),
            ],
        ),
        (
            Ent(400, 572.0, 9, 20, 0, -1, 0),
            [
                Ent(377, 540, 32, 32, 0, 0, 0),
                Ent(400, 540, 32, 32, 0, 0, 0),
            ],
        ),
    ],
)
def test_collision_gravity_hit(main, cols):
    result, col = resolve_all_collision(main, cols)

    assert col.hit == 1
    assert result.y == round(col.new_y + 0.5)
    assert result.x == round(col.new_x + 0.5)
    assert result.vx == 0
    assert result.vy == 0



@pytest.mark.parametrize(
    "main, cols",
    [
        (
            Ent(368, 578, 9, 20, 0, -6, 0),
            [
                Ent(377, 540, 32, 32, 0, 0, 0),
                Ent(409, 540, 32, 32, 0, 0, 0),
            ],
        ),
        (
            Ent(377, 578, 9, 20, 0, -6, 0),
            [
                Ent(377, 540, 32, 32, 0, 0, 0),
                Ent(409, 540, 32, 32, 0, 0, 0),
            ],
        ),
        (
            Ent(400, 578, 9, 20, 0, -6, 0),
            [
                Ent(377, 540, 32, 32, 0, 0, 0),
                Ent(409, 540, 32, 32, 0, 0, 0),
            ],
        ),
        (
            Ent(409, 578, 9, 20, 0, -6, 0),
            [
                Ent(377, 540, 32, 32, 0, 0, 0),
                Ent(409, 540, 32, 32, 0, 0, 0),
            ],
        ),
        (
            Ent(441, 578, 9, 20, 0, -6, 0),
            [
                Ent(377, 540, 32, 32, 0, 0, 0),
                Ent(409, 540, 32, 32, 0, 0, 0),
            ],
        ),
    ],
)
def test_collision_gravity_collision_hit_edge(main, cols):
    result, col = resolve_all_collision(main, cols)

    assert col.hit == 0
    assert result.y == round(col.new_y + 0.5)
    assert result.x == round(col.new_x + 0.5)
    assert result.vx == 0
    assert result.vy == main.vy


@pytest.mark.parametrize(
    "main, cols, ex_vx, ex_vy",
    [
        (
            Ent(400, 572, 9, 20, +6, -8, 0),
            [
                Ent(377, 540, 32, 32, 0, 0, 0),
                Ent(409, 540, 32, 32, 0, 0, 0),
            ],
            6,
            0,
        ),
        (
            Ent(409, 572, 9, 20, +6, -8, 0),
            [
                Ent(377, 540, 32, 32, 0, 0, 0),
                Ent(409, 540, 32, 32, 0, 0, 0),
            ],
            6,
            0,
        ),
        (
            Ent(400, 572, 9, 20, +6, -5, 0),
            [
                Ent(377, 540, 32, 32, 0, 0, 0),
                Ent(409, 540, 32, 32, 0, 0, 0),
            ],
            6,
            0,
        ),
        (
            Ent(409, 572, 9, 20, +6, -5, 0),
            [
                Ent(377, 540, 32, 32, 0, 0, 0),
                Ent(409, 540, 32, 32, 0, 0, 0),
            ],
            6,
            0,
        ),
    ],
)
def test_collision_multiple_velocities_hit_is_true(main, cols, ex_vx, ex_vy):
    result, col = resolve_all_collision(main, cols)

    assert col.hit == 1
    assert result.y == round(col.new_y + 0.5)
    assert result.x == round(col.new_x + 0.5)
    assert result.vx == ex_vx
    assert result.vy == ex_vy


@pytest.mark.parametrize("vx", [-8, 7, -5, -1, 3, 4])
@pytest.mark.parametrize("vy", [-8, -7, -6, -5])
def test_tryy_to_find_error(vx, vy):
    cols =  [
        Ent(377, 540, 32, 32, 0, 0, 0),
        Ent(409, 540, 32, 32, 0, 0, 0),
    ]
    main = Ent(409, 572, 9, 20, 0, 0, 0)
    main.vx = vx
    main.vy = vy

    result, col = resolve_all_collision(main, cols)

    assert col.hit == 1
    assert result.y == 572
    assert result.x == round(col.new_x + 0.5)


@pytest.mark.parametrize(
    "main",
    [
        Ent(409, 572, 9, 20, 0, 0, 0),
        Ent(400, 572, 9, 20, 0, 0, 0),
    ]
)
def test_tryy_to_find_error2(main):
    vx = -5.0 
    vy = -8.0

    cols =  [
        Ent(377, 540, 32, 32, 0, 0, 0),
        Ent(409, 540, 32, 32, 0, 0, 0),
    ]

    main.vx = vx
    main.vy = vy

    result, col = resolve_all_collision(main, cols)

    assert col.hit == 1
    assert result.y == 572
    assert result.x == round(col.new_x + 0.5)
