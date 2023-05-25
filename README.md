# so_long

so_long is a project from 42 Lisboa and the main purpose is to create a 2D Game. I did my own theme like a robbery that the player needs to get all the money and then going to the exit.

### Skills

* Window management
* Event handling
* Image manipulation
* Usage of graphical library (MinilibX)

## Some Rules about the project

* Program only accepts map files with ".ber" extension, by command line argument
* The map should have only the following characters:
* 'P' for player (only one)
* 'C' for ring (at leaste one)
* 'E' for exit (only one)
* '1' for wall
* '0' for free way
* The map must be surrounded for walls
* The map must be rectangular
* If one of these requirements are not ok, the program returns an error and cleans all the heap memory.

The program runs only on Linux. If you want to play, use the following commands
```
git clone https://github.com/luidjidev/so_long.git
cd src/
make
./so_long map/(any map avaible on the folder)
```
You can change the map, changing the path. Another option is "../maps/map2.ber". You can even make your own maps! But remember to respect the map rules!

Use the keys 'W', 'A', 'S' and 'D' to move the player and 'ESC' or 'x' button to quit. The exit only opens when all the rings are collected. If Sonic touchs Robotinik the game is over.

Anything you can DM me on slack luisfern :)
