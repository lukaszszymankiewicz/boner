CC = gcc
CFLAGS := --std=c99
WARNINGFLAGS := -Wall
DEBUGFLAGS := -g
LINKS = `pkg-config --cflags --libs sdl2 SDL2_image` 
LIBS = -lGL -lGLU -lGLEW -lm 
STATIC_LIBS = /usr/lib/x86_64-linux-gnu/libSDL2.a /usr/lib/x86_64-linux-gnu/libSDL2_image.so -lm -ldl -lasound -lm -ldl -lpthread -lpulse-simple -lpulse -lX11 -lXext -lXcursor -lXinerama -lXi -lXrandr -lXss -lXxf86vm -ldrm -lgbm -lwayland-egl -lwayland-client -lwayland-cursor -lxkbcommon -lpthread -lrt -lGL -lGLU -lGLEW -lm

FINAL_OBJ = boner
BPT_FINAL_OBJ = bpt
SRCDIR = src
BUILDDIR = build
RENDER = obscura
BPTDIR = bpt

$(BUILDDIR)/%.o:	$(SRCDIR)/%.c
	$(CC) $(CFLAGS) $(DEBUGFLAGS) -c $< -o $@

$(BUILDDIR)/$(RENDER)/%.o: $(SRCDIR)/$(RENDER)/%.c
	$(CC) $(CFLAGS) $(DEBUGFLAGS) -c $< -o $@

$(BUILDDIR)/$(BPTDIR)/%.o: $(SRCDIR)/$(BPTDIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

BPTCFILES =                             \
	$(SRCDIR)/$(BPTDIR)/entities.c      \
	$(SRCDIR)/$(BPTDIR)/levels.c        \
	$(SRCDIR)/$(BPTDIR)/library.c       \

BPTOBJS =                                 \
	$(BUILDDIR)/$(BPTDIR)/entities.o      \
	$(BUILDDIR)/$(BPTDIR)/levels.o        \
	$(BUILDDIR)/$(BPTDIR)/library.o       \

CFILES =                                 \
	$(SRCDIR)/$(RENDER)/framebuffer.c    \
	$(SRCDIR)/$(RENDER)/gfx.c            \
	$(SRCDIR)/$(RENDER)/mat.c            \
	$(SRCDIR)/$(RENDER)/canvas.c         \
	$(SRCDIR)/$(RENDER)/shader.c         \
	$(SRCDIR)/$(RENDER)/shaders.c        \
	$(SRCDIR)/$(RENDER)/texture.c        \
    $(SRCDIR)/$(RENDER)/render.c         \
    $(SRCDIR)/$(RENDER)/window.c         \
	$(SRCDIR)/collision.c                \
	$(SRCDIR)/controller.c               \
	$(SRCDIR)/datatable.c                \
	$(SRCDIR)/data.c                     \
	$(SRCDIR)/entity.c                   \
	$(SRCDIR)/game.c                     \
	$(SRCDIR)/geometry.c                 \
	$(SRCDIR)/level_manager.c            \
	$(SRCDIR)/resources.c                \
	$(SRCDIR)/main.c                     \
	$(SRCDIR)/modules.c                  \
	$(SRCDIR)/system.c                   \
	$(SRCDIR)/system_manager.c           \
	$(SRCDIR)/timer.c                    \

OBJS =                                     \
	$(BUILDDIR)/$(RENDER)/framebuffer.o    \
	$(BUILDDIR)/$(RENDER)/gfx.o            \
	$(BUILDDIR)/$(RENDER)/mat.o            \
    $(BUILDDIR)/$(RENDER)/render.o         \
	$(BUILDDIR)/$(RENDER)/canvas.o         \
	$(BUILDDIR)/$(RENDER)/shader.o         \
	$(BUILDDIR)/$(RENDER)/shaders.o        \
	$(BUILDDIR)/$(RENDER)/texture.o        \
	$(BUILDDIR)/$(RENDER)/window.o         \
	$(BUILDDIR)/collision.o                \
	$(BUILDDIR)/controller.o               \
	$(BUILDDIR)/datatable.o                \
	$(BUILDDIR)/data.o                     \
	$(BUILDDIR)/entity.o                   \
	$(BUILDDIR)/game.o                     \
	$(BUILDDIR)/geometry.o                 \
	$(BUILDDIR)/level_manager.o            \
	$(BUILDDIR)/resources.o                \
	$(BUILDDIR)/modules.o                  \
	$(BUILDDIR)/system.o                   \
	$(BUILDDIR)/system_manager.o           \
	$(BUILDDIR)/timer.o                    \

$(BUILDDIR)/boner:	$(OBJS) $(BUILDDIR)/main.o
	$(CC) $(CFLAGS) $(WARNINGFLAGS) $(DEBUGFLAGS) $(OBJS) $(BUILDDIR)/main.o -o $(BUILDDIR)/$(FINAL_OBJ) $(LINKS) $(LIBS)

$(BUILDDIR)/$(BPTDIR)/bpt: $(BPTOBJS) $(BUILDDIR)/$(BPTDIR)/main.o
	$(CC) $(CFLAGS) $(BPTOBJS) $(BUILDDIR)/$(BPTDIR)/main.o -o $(BUILDDIR)/$(BPTDIR)/$(BPT_FINAL_OBJ) 

clean:
	rm -f $(BUILDDIR)/*.o
	rm -f $(BUILDDIR)/$(RENDER)/*.o
	rm -f $(BUILDDIR)/$(BPTDIR)/*.o
	rm -f $(BUILDDIR)/$(BPTDIR)/$(FINAL_OBJ)
	rm -f $(BUILDDIR)/$(FINAL_OBJ)
	rm -f -R $(BUILDDIR)/$(RENDER)
	rm -f -R $(BUILDDIR)/$(BPTDIR)
	rm -f -R $(BUILDDIR)
	rm -f boner

structure:
	mkdir -p $(BUILDDIR) $(BUILDDIR)/$(RENDER) $(BUILDDIR)/$(BPTDIR)

boner:  $(BUILDDIR)/boner

bpt:  $(BUILDDIR)/$(BPTDIR)/bpt

run_boner:
	./$(BUILDDIR)/$(FINAL_OBJ)

run_bpt:
	./$(BUILDDIR)/$(BPTDIR)/$(BPT_FINAL_OBJ)

all: 
	make structure boner run_boner

debug: 
	gdb ./$(BUILDDIR)/$(FINAL_OBJ)

static: 
	$(CC) $(CFLAGS) $(CFILES) -o $(FINAL_OBJ) $(STATIC_LIBS)

profile: 
	gprof ./$(BUILDDIR)/$(FINAL_OBJ) gmon.out  > gmon.txt

memory_check:
	valgrind --leak-check=yes --log-file="memory_check.txt" --track-origins=yes --leak-check=full --show-leak-kinds=all ./build/boner
