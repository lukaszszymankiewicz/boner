CC = gcc
CFLAGS := --std=c99
WARNINGFLAGS := 
DEBUGFLAGS := 
LINKS = `pkg-config --cflags --libs sdl2 SDL2_image` 
LIBS = -lGL -lGLU -lGLEW -lm 
STATIC_LIBS = /usr/lib/x86_64-linux-gnu/libSDL2.a /usr/lib/x86_64-linux-gnu/libSDL2_image.so -lm -ldl -lasound -lm -ldl -lpthread -lpulse-simple -lpulse -lX11 -lXext -lXcursor -lXinerama -lXi -lXrandr -lXss -lXxf86vm -ldrm -lgbm -lwayland-egl -lwayland-client -lwayland-cursor -lxkbcommon -lpthread -lrt -lGL -lGLU -lGLEW -lm

FINAL_OBJ = boner
SRCDIR = src
BUILDDIR = build
DATADIR = data
MODDIR = modules

$(BUILDDIR)/%.o:	$(SRCDIR)/%.c
	$(CC) $(CFLAGS) $(DEBUGFLAGS) -c $< -o $@

$(BUILDDIR)/$(DATADIR)/%.o:	$(SRCDIR)/$(DATADIR)/%.c
	$(CC) $(CFLAGS) $(DEBUGFLAGS) -c $< -o $@

CFILES =                                   \
	$(SRCDIR)/$(DATADIR)/behaviours.c    \
	$(SRCDIR)/$(DATADIR)/entities.c      \
	$(SRCDIR)/$(DATADIR)/levels.c        \
	$(SRCDIR)/$(DATADIR)/library.c       \
	$(SRCDIR)/$(DATADIR)/shaders.c       \
	$(SRCDIR)/$(DATADIR)/sprites.c       \
	$(SRCDIR)/animation.c                \
	$(SRCDIR)/behaviour.c                \
	$(SRCDIR)/collision.c                \
	$(SRCDIR)/controller.c               \
	$(SRCDIR)/entity.c                   \
	$(SRCDIR)/entity_manager.c           \
	$(SRCDIR)/framebuffer.c              \
	$(SRCDIR)/game.c                     \
	$(SRCDIR)/geometry.c                 \
	$(SRCDIR)/gfx.c                      \
	$(SRCDIR)/level.c                    \
	$(SRCDIR)/level_manager.c            \
	$(SRCDIR)/main.c                     \
	$(SRCDIR)/mat.c                      \
	$(SRCDIR)/modules.c                  \
	$(SRCDIR)/scene.c                    \
	$(SRCDIR)/shader.c                   \
	$(SRCDIR)/system.c                   \
	$(SRCDIR)/system_manager.c           \
	$(SRCDIR)/texture.c                  \
	$(SRCDIR)/timer.c                    \
	$(SRCDIR)/window.c                   \
    $(SRCDIR)/render.c                   \

OBJS =                                     \
	$(BUILDDIR)/$(DATADIR)/behaviours.o    \
	$(BUILDDIR)/$(DATADIR)/entities.o      \
	$(BUILDDIR)/$(DATADIR)/levels.o        \
	$(BUILDDIR)/$(DATADIR)/library.o       \
	$(BUILDDIR)/$(DATADIR)/shaders.o       \
	$(BUILDDIR)/$(DATADIR)/sprites.o       \
	$(BUILDDIR)/animation.o                \
	$(BUILDDIR)/behaviour.o                \
	$(BUILDDIR)/modules.o                  \
	$(BUILDDIR)/controller.o               \
	$(BUILDDIR)/collision.o                \
	$(BUILDDIR)/entity.o                   \
	$(BUILDDIR)/entity_manager.o           \
	$(BUILDDIR)/framebuffer.o              \
	$(BUILDDIR)/game.o                     \
	$(BUILDDIR)/geometry.o                 \
	$(BUILDDIR)/gfx.o                      \
	$(BUILDDIR)/level.o                    \
	$(BUILDDIR)/level_manager.o            \
	$(BUILDDIR)/mat.o                      \
	$(BUILDDIR)/scene.o                    \
	$(BUILDDIR)/shader.o                   \
	$(BUILDDIR)/system.o                   \
	$(BUILDDIR)/system_manager.o           \
	$(BUILDDIR)/texture.o                  \
	$(BUILDDIR)/timer.o                    \
	$(BUILDDIR)/window.o                   \
    $(BUILDDIR)/render.o                   \

$(BUILDDIR)/boner:	$(OBJS) $(BUILDDIR)/main.o
	$(CC) $(CFLAGS) $(WARNINGFLAGS) $(DEBUGFLAGS) $(OBJS) $(BUILDDIR)/main.o -o $(BUILDDIR)/$(FINAL_OBJ) $(LINKS) $(LIBS)

clean:
	rm -f $(BUILDDIR)/*.o
	rm -f $(BUILDDIR)/$(DATADIR)/*.o
	rm -f $(BUILDDIR)/$(MODDIR)/*.o
	rm -f $(BUILDDIR)/$(FINAL_OBJ)
	rmdir -p $(BUILDDIR) 2>/dev/null
	rm -f boner

structure:
	mkdir -p $(BUILDDIR) $(BUILDDIR)/$(DATADIR) $(BUILDDIR)/$(MODDIR)

boner:  $(BUILDDIR)/boner

run_boner:
	./$(BUILDDIR)/$(FINAL_OBJ)

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
