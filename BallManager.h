//BallManager.h

#ifndef _BALLMANAGER_H_
    #define _BALLMANAGER_H_

#include <Ball.h>
#include <Simulator.h>
#include <string>

class BallManager{
	private:
		std::vector<Ball*> ball_list;
	public:
		BallManager();
		void addBall(Ball* ball);
		void updateBalls();
		int size();
		Ball* getNearestBall(Ogre::Vector3 playerloc);
		Ball* getBall(int i);

		static BallManager BallControl;
};

#endif
