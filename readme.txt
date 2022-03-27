For the Hero and Enemies, we introduce a verb hierarchy (see class diagram below). 
The top-level base class is now the Character class, which contains all the properties and behavior shared by the two subclasses Hero and NPC (and their subclasses). 
The NPC class represents the base class for all enemies.


Again, store each class in its own source files (hero.{h, cpp}, character.{h, cpp}, npc.{h, cpp}, sorcerer.{h, cpp}, fighter.{h, cpp} and item.{h, cpp}). 
The main function should be found in the main.cpp file.


Convert all previous init functions into constructors. Add any additional constructors that seem appropriate.
