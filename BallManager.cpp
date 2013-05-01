//BallManager.cpp
#include "BallManager.h"

BallManager BallManager::BallControl;
std::vector<Ball*> ball_list;

BallManager::BallManager(){}

void BallManager::addBall(Ball* ball){
	ball_list.push_back(ball);
}

Ball* BallManager::getNearestBall(Ogre::Vector3 playerloc){
	Ball* closestSoFar = ball_list[0];
	for(int i = 1; i < ball_list.size(); i++){
		if( (playerloc - ball_list[i]->getPosition()) < (playerloc - closestSoFar->getPosition()) )
			closestSoFar = ball_list[i];
	}
	return closestSoFar;
}