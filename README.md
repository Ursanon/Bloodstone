# Bloodstone
[![Codacy Badge](https://api.codacy.com/project/badge/Grade/eef5d96748a5481b87d02fb0bc5f06e5)](https://app.codacy.com/manual/Ursanon/Bloodstone?utm_source=github.com&utm_medium=referral&utm_content=Ursanon/Bloodstone&utm_campaign=Badge_Grade_Dashboard)

## About
Proof of concept: Game Engine based on SFML.

Current feature set:
*   Component-based game entities architecture
*   Dynamic configuration parser (`JSON`)
*   Custom math
*   Custom time measurement classes
*   Dynamically loading assets
*   Assets configuration parsing
*   Fixed timestamp main loop and fps lock
*   Simple scene system

Simple demo of technology for assignment on University of Lower Silesia.  
Future development plans:
*   ~~Port to SFML~~
*   Custom rendering framework
*   Physics 
*   Front-end GUI components
*   Editor
*   Debugging & profiling tools

## Planned scheme
[![Scheme](docs/bloodstone.png)](docs/bloodstone.png)

## How to build
1.  Clone repository
2.  Run `cmake` (provide path to SFML - [see example settings](https://github.com/Ursanon/Bloodstone/blob/master/CMakeSettings.json))

## Download latest release
Download from [Releases](https://github.com/Ursanon/Bloodstone/releases)