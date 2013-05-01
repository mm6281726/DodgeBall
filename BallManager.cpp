//BallManager.cpp
#include "BallManager.h"

BallManager BallManager::BallControl;
std::vector<Ball*> ball_list;

BallManager::BallManager(){}

void BallManager::addBall(Ball* ball){
	ball_list.push_back(ball);
}

int BallManager::size(){
	return ball_list.size();
}

void BallManager::updateBalls(){
	for(int i = 0; i < ball_list.size(); i++){
		Ball* ball = ball_list[i];
		btTransform t;
    	ball->getBody()->getMotionState()->getWorldTransform(t);
    	btVector3 position = t.getOrigin();
    	ball->setPosition(Ogre::Vector3((float)position[0],(float)position[1],(float)position[2]));
	}
}

Ball* BallManager::getNearestBall(Ogre::Vector3 playerloc){
	Ball* closestSoFar = ball_list[0];
	for(int i = 1; i < ball_list.size(); i++){
		if( (playerloc - ball_list[i]->getPosition()) < (playerloc - closestSoFar->getPosition()) )
			closestSoFar = ball_list[i];
	}
	return closestSoFar;
}

Ball* BallManager::getBall(int i){
	return ball_list[i];
}