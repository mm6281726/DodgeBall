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
	ball->bounceCheck();
	}
}

Ball* BallManager::getNearestBall(Ogre::Vector3 playerloc){
	Ball* closest;
	float nearest=50000;
	for(int i = 0; i < ball_list.size(); i++){
		Ogre::Vector3 dist = playerloc - ball_list[i]->getPosition();
		if(dist.length()<nearest){
			closest = ball_list[i];
			nearest=dist.length();
		}
	}
	return closest;
}

Ball* BallManager::getBall(int i){
	return ball_list[i];
}
