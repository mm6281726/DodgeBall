//BallManager.h

#ifndef _BALLMANAGER_H_
    #define _BALLMANAGER_H_

#include <Ball.h>
#include <string>

class BallManager{
	private:
		std::vector<Ball*> ball_list;
	public:
		BallManager();
		void addBall(Ball* ball);
		Ball* getNearestBall(Ogre::Vector3 playerloc);

		static BallManager BallControl;
};

#endif
