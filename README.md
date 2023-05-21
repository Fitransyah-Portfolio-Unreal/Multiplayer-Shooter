# Multiplayer Shooter Prototype 

This project demonstrating multiplayer sistem in Unreal.  
Multiplayer system is handled by costum plugin (MultiplayerSession) that I created to interact with Unreal Online Subsystem interface. 
All assets are free assets mainly from Mixamo and Unreal marketplace.   

# Development progress  

Below every section will explain all development activity.  
Every section is named same with the push title.    

## Section 1  Project fundamentals  
- Started with empty project with the Multiplayer session plugin.  
- Main character creation with C++ equipped with copied locomotion system from Unreal third person charactert template, cameras.  
- Assets preparation, animations, 3D models for weapons and assets level.  
- Make LobbyPlayerController class for handling seamless travel when enough players present in the lobby.  
- Basic Menu widget from plugin.  
- Player overhead widget for player information.  
- Creating 3 basic level in the world :  
    - Startup level, where the player start and choose to host or join session.  
    - Lobby level, where player can move and interact with the level and other player while waiting other player to join.  
    - Multiplayer level, where player will start and play the game with other players.  

## Section 2 Character, Locomotion, Combat and Weapon
- Working on character movement equip or unequip
- Adding aim offset for equip state
- Creation of Weapon class and behaviour
- Animation and special effects 

