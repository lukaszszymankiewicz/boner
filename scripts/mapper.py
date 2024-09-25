"""script to convert raw level from riskylab format to boner native format"""

import sys
from typing import List, Optional
import os
import json

SECTOR_W: int = 160
SECTOR_H: int = 120
LAYERS: int = 2
BASE_MAP: int = 6
ENT_RECORDS: int = 50
COLLISION_BODY_SOLID: int = 0
ID: str = "ID"
LEVEL_WIDTH: str = "LEVEL_WIDTH"  
LEVEL_SIZE_X: str = "LEVEL_SIZE_X" 
LEVEL_SIZE_Y: str = "LEVEL_SIZE_Y" 
LEVEL_FOCUS_X: str = "LEVEL_FOCUS_X"
LEVEL_FOCUS_Y: str = "LEVEL_FOCUS_Y"
MAP: str = "MAP"
METADATA: str = "METADATA"
ENTITY_DATA: str = "ENTITY_DATA"
ENTITY_NTH: str = "ENTITY_NTH"

ENTITY_COMPONENT_BPT: str = "ENTITY_COMPONENT_BPT"
ENTITY_COMPONENT_PHASES: str = "ENTITY_COMPONENT_PHASES"
ENTITY_COMPONENT_X_POS: str = "ENTITY_COMPONENT_X_POS"
ENTITY_COMPONENT_Y_POS: str = "ENTITY_COMPONENT_Y_POS"
ENTITY_COMPONENT_FRAME_X: str = "ENTITY_COMPONENT_FRAME_X"
ENTITY_COMPONENT_FRAME_Y: str = "ENTITY_COMPONENT_FRAME_Y"
ENTITY_COMPONENT_FRAME_W: str = "ENTITY_COMPONENT_FRAME_W"
ENTITY_COMPONENT_FRAME_H: str = "ENTITY_COMPONENT_FRAME_H"
ENTITY_COMPONENT_LAYER: str = "ENTITY_COMPONENT_LAYER"
ENTITY_COMPONENT_COLLISIONABLE: str = "ENTITY_COMPONENT_COLLISIONABLE"
AVAILABLE_COMPONENTS: str = 31

PHASE_FLAG_INIT: str = "PHASE_FLAG_INIT"
PHASE_FLAG_PRE: str = "PHASE_FLAG_PRE"
PHASE_FLAG_CONTROL: str = "PHASE_FLAG_CONTROL"
PHASE_FLAG_UPDATE: str = "PHASE_FLAG_UPDATE"
PHASE_FLAG_COLLISION: str = "PHASE_FLAG_COLLISION"
PHASE_FLAG_RESOLVE: str = "PHASE_FLAG_RESOLVE"
PHASE_FLAG_DRAW: str = "PHASE_FLAG_DRAW"

TILE: str = "ENTITY_TILE"
HERO: str = "ENTITY_SKELETON"

TILE_FLAGS = "+".join([PHASE_FLAG_INIT, PHASE_FLAG_DRAW])
PHASE_FLAG_ALL = "+".join([PHASE_FLAG_INIT, PHASE_FLAG_PRE,
                            PHASE_FLAG_CONTROL, PHASE_FLAG_UPDATE,
                            PHASE_FLAG_COLLISION, PHASE_FLAG_RESOLVE,
                            PHASE_FLAG_DRAW])

class Counter:
    def __init__(self, st: int = 0):
        self.st = st
    
    def increase(self):
        self.st += 1

    def set(self, val):
        self.st = val

    def get(self):
        self.increase()

        return self.st

    def get_ent_idx(self):
        self.increase()

        if (self.st % ENT_RECORDS) == 0:
            return self.st

        self.st += ENT_RECORDS
        self.st = (self.st // ENT_RECORDS) * ENT_RECORDS

        return self.st

class Record:
    children: Optional[List["Record"]] = None

    def __init__(self, key, a, b, c, d):
        self.key = key

        self.a = a
        self.b = b
        self.c = c
        self.d = d
    
    def __repr__(self):
        return f"{self.key} | {self.a} {self.b} {self.c} {self.d}"

    def width(self):
        res = 1

        if self.children:

            for c in self.children:
                res += c.width()

        return res
    
    def printt(self, level: int = 4):
        tab = " " * level * 2
        print(tab + "{" + f"{self.key}, {self.a}, {self.b}, {self.c}, {self.d}" + "},")

        if self.children:
            for child in self.children:
                child.printt(level=level+1)

    def unique(self):
        keys = []

        keys.append(self.key)

        if self.children:

            for child in self.children:
                keys.extend(child.unique())

        return keys

counter = Counter(-1)

class RecordCollection:
    def __init__(self, records = None):
        self.records = records

    def printt(self):
        if not self.records:
            return

        for r in self.records:
            r.printt()

    def append(self, a, b, c, d):
        if not self.records:
            self.records = []

        self.records.append(Record(counter.get(), a, b, c, d))

    def find(self, a=None, b=None, c=None):
        for r in self.records:
            if r.a == a and r.b == b and r.c == c:
                return r

    def width(self):
        res = 0 

        for r in self.records:
            res += r.width()

        return res
    
    def unique(self):
        keys = []

        for r in self.records:
            keys.extend(r.unique())
        
        if len(set(keys)) == (keys):
            return False

        return True
    
    def add_entity(
        self,
        sec_x,
        sec_y,
        bpt,
        flags,
        pos_x,
        pos_y,
        x = -1,
        y = -1,
        w = -1,
        h = -1,
        layer = 1
    ):
        """Best code ever."""

        sec_map = self.find(MAP, sec_y, sec_x)

        assert(len(sec_map.children) == 1)

        meta = sec_map.children[0]
        meta.key = counter.get()
        sec_map.d = meta.key
        meta.d += 1

        n_ents = 0

        if meta.children is not None:
            n_ents = len(meta.children)
        
        if meta.children is not None:
            for map_ in meta.children:
                map_.key = counter.get()

        # new
        ent_map = Record(counter.get(), MAP, 0, 0, -1)
        ent_idx = counter.get_ent_idx()

        ent_map.d = ent_idx
        ent_map.c = n_ents
        
        r = [
            Record(str(ent_idx), ENTITY_NTH, sec_x, sec_y, n_ents),
            Record(str(ent_idx) + " + " + ENTITY_COMPONENT_BPT, ENTITY_DATA, 0, 0, bpt),
            Record(str(ent_idx) + " + " + ENTITY_COMPONENT_X_POS, ENTITY_DATA, 0, 0, pos_x),
            Record(str(ent_idx) + " + " + ENTITY_COMPONENT_Y_POS, ENTITY_DATA, 0, 0, pos_y),
            Record(str(ent_idx) + " + " + ENTITY_COMPONENT_PHASES, ENTITY_DATA, 0, 0, flags),
            Record(str(ent_idx) + " + " + ENTITY_COMPONENT_LAYER, 0, 0, 0, layer)
        ]

        if x!=-1:
            r.append(Record(str(ent_idx) + " + " + ENTITY_COMPONENT_FRAME_X, ENTITY_DATA, 0, 0, x))
        
        if y!=-1:
            r.append(Record(str(ent_idx) + " + " + ENTITY_COMPONENT_FRAME_Y, ENTITY_DATA, 0, 0, y))

        if w!=-1:
            r.append(Record(str(ent_idx) + " + " + ENTITY_COMPONENT_FRAME_W, ENTITY_DATA, 0, 0, w))

        if h!=-1:
            r.append(Record(str(ent_idx) + " + " + ENTITY_COMPONENT_FRAME_H, ENTITY_DATA, 0, 0, h))

        if layer==1:
            r.append(Record(str(ent_idx) + " + " + ENTITY_COMPONENT_COLLISIONABLE, ENTITY_DATA, 0, 0, COLLISION_BODY_SOLID))

        if not ent_map.children:
            ent_map.children = []

        ent_map.children.extend(r)

        if not meta.children:
            meta.children = []

        meta.children.append(ent_map)
        counter.st += AVAILABLE_COMPONENTS

def create_map(path, focus_x: int=7, focus_y: int=7):

    with open(path) as f:
        data = json.load(f)

    mapp = RecordCollection()

    size_x = int(data['canvas']['width'] / SECTOR_W) + 1
    size_y = int(data['canvas']['height'] / SECTOR_H) + 1
    tile_x = int(data['canvas']['width'] // 32)
    tile_y = int(data['canvas']['height'] // 32)

    mapp.append(ID, 0, 0, 666)
    mapp.append(LEVEL_WIDTH,   0, 0, 0)
    mapp.append(LEVEL_SIZE_X,  0, 0, size_x)
    mapp.append(LEVEL_SIZE_Y,  0, 0, size_y)
    mapp.append(LEVEL_FOCUS_X, 0, 0, focus_x)
    mapp.append(LEVEL_FOCUS_Y, 0, 0, focus_y)

    for x in range(size_x+1):
        for y in range(size_y+1):
            meta = Record(6 + y * size_y + x, MAP, x, y, 0)
            mapp.records.append(meta)

    counter.set(meta.key)
    max_map = meta.key

    for x in range(size_x+1):
        for y in range(size_y+1):

            map_ = mapp.find(MAP, x, y)

            assert(x == map_.b)
            assert(y == map_.c)
            assert(6 + y * size_y + x == map_.key);

            meta = Record(counter.get(), METADATA, x, y, 0)
            assert(meta.key > max_map)

            map_.children = [meta]
            map_.d = meta.key


    for l in range(LAYERS):
        for i, d in enumerate(data["layers"][l]["data"]):

            if d == -1:
                continue
            
            # extract the data
            pos_x = (i % tile_x) * 32
            pos_y = (tile_y - (i // tile_x)) * 32
            
            sec_x = pos_x // SECTOR_W
            sec_y = pos_y // SECTOR_H

            if isinstance(d, int):
                d = float(d)

            frame_x = int(str(d).split('.')[0])
            frame_y = int(str(d).split('.')[1])

            flags = TILE_FLAGS

            mapp.add_entity(
                sec_x=sec_x,
                sec_y=sec_y,
                bpt=TILE,
                flags=flags,
                pos_x=pos_x,
                pos_y=pos_y,
                x=frame_x*32,
                y=frame_y*32,
                w=32,
                h=32,
                layer=l
            )

    mapp.add_entity(
        focus_x, focus_y,
        HERO, PHASE_FLAG_ALL,
        1186, 864,
        layer=2
    )

    mapp.records[1].d = mapp.width()
    mapp.printt()

if __name__ == '__main__':
    file_name = os.path.join(sys.path[0], 'map.json')
    create_map(file_name)
