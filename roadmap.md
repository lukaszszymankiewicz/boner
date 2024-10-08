ROADMAP

version 0.0.1
 - [x] make sectors oriented from bottom left goddamit! (add some private
   methods)
 - [x] sectors to another module
 - [x] sector to have dynamically numerb of entites
 - [x] some more sofisticated ECS
 - [x] compman to another module
 - [x] remove entity_manger
 - [x] remove ent from context
 - [x] remove new idea file
 - [x] fill the entity with defaults
 - [x] anim to new format as well
 - [x] delete wobbles
 - [x] move basic level grabbing methods with DATA
 - [x] level.c should be something like data.c, lvlman.c should be level (?)
 - [x] remove **ALL** TODOs!
 - [x] delete unused fun
 - [x] cooler level + better script to use htps://riskylab.com/tilemap/ format
 - [x] data to separate independent files (maybe Resourcer implementation?)
  - [x] behaviours to ent files (ent files)
  - [x] collision behaviours to ent files (ent files)
  - [x] rendering stuff (with shaders!) to another subfolder/library
  - [x] SCENE renamed to CANVAS
  - [x] scaling is too big after changes
  - [x] slice Makefile to game/obscura (wont do)
  - [x] serialize ents and levels and put it into data files
   - [x] rename data folder to bpt
   - [x] add dummy serializer/desierializer
   - [x] check if reading files works
   - [x] move serializing elsewhere
     [x] rename LIB prefix to BPT
   - [x] move sprites to separate folder
   - [x] add some global typedef of int32_t and size of base_int
   - [x] add resources implementaion (store the paths in some c file by now)
  - [x] slice Makefile to game/bpt
 - [x] resolve issues with new level system
  - [x] hero is not in the middle
  - [x] moving by secotrs crash
  - [x] test it on better level

version 0.0.2
 - [x] scale the skeleton entity to better fit the 32x32 tiles
  - [x] apprioprietly set the skeleton frames! (gun in sliced now!)
 - [x] animation frame is not correctly set 
 - [x] flipping the frame does not work
 - [x] remove all TODOs
 - [x] resources should be freed corectly
 - [x] strange thrills while jumping high
  - [x] holding jump button allows to jump infinitely
  - [x] scale falling down speed to new size of skeleton
  - [x] add origin point to animation data - right now it is always the
    highest-left point of frame but it should be modifiable (done by properly
    setting the frame image)
 - [x] skeleton does not stop walking after losing all the x-velocity
 - [x] segfaults while playing (try jumping four times to achieve this behaviour)
  - [x] jumping is ok
  - [x] failing down sucks
 - [ ] tweak the hero moving components values
 - [ ] third platform from left has some collision issues
 - [ ] remove ent metadata in level

version 0.0.3
 - [ ] behaviours should have its own basic scripting language (rethink it!)
 - [ ] some easy way to record gameplay (and replay it)
 - [ ] refine hitboxes (guns should propably be out of hitbox of skeleton)
 - [ ] refine components: right now component can hold only one value, but there
   is a place for four of them! (sic!)

UTILS:
 - [ ] rethink modules
