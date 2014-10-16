#pragma once

#ifdef _DEBUG
#pragma comment(lib,"sfml-graphics-d.lib")
#pragma comment(lib,"sfml-audio-d.lib")
#pragma comment(lib,"sfml-system-d.lib")
#pragma comment(lib,"sfml-window-d.lib")
#pragma comment(lib,"sfml-network-d.lib")
#else
#pragma comment(lib,"sfml-graphics.lib")
#pragma comment(lib,"sfml-audio.lib")
#pragma comment(lib,"sfml-system.lib")
#pragma comment(lib,"sfml-window.lib")
#pragma comment(lib,"sfml-network.lib")
#endif
#pragma comment(lib,"opengl32.lib")
#pragma comment(lib,"glu32.lib") 
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <algorithm>
#include <list>

#include "tile.h"


#define GRIDW 50
#define GRIDH 50
#define RADIUS 5
#define TILEW 10
#define TILEH 10
#define MAXVISION 5
#define MAXMETABOL 5

enum Sex{
	M,
	F
};

class Agent : public sf::CircleShape 
{
private:
	int x;
	int y;
	double sugar;
	int sugarStart;
	short int vision;
	double metabolism;
	short int maxAge;
	short int age;
	Sex	gender; 

	
	void sex(Tile[][GRIDH], std::list<Agent>&);
	void move(Tile[][GRIDH]);

public:
	Agent();
	Agent(int x, int y);
	Agent(int x, int y, int wealth, double met, int vis);
	
	bool update(Tile[][GRIDH], std::list<Agent>&, int s);
	sf::Vector2i getCoord();
	int getWealth();
	int getMetabolRate();
	Sex getGender();
	bool isFertile();
};

struct point {
	int x;
	int y;
	int dist;
	point(int px, int py, int pdist){x=px;y=py;dist=pdist;}
	bool operator<( const point& val ) const { 
    	return dist < val.dist; 
    }
};