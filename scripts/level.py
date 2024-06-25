x_sectors = 5
y_sectors = 5
w = 160
h = 128

tile_per_x = (int)(w / 32)
tile_per_y = (int)(h / 32)

for xi in range(x_sectors):
    print("{")
    for yi in range(y_sectors):
        print("  {")
        for r in range(tile_per_x):
            for c in range(tile_per_y):
                x = 32 * r + w * xi
                y = 32 * c + h * yi
                print("    {" + f"{x}, {y}, ENTITY_BASE_TILE" + "},")
        print("  },")
    print("}")
