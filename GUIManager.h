//GUIManager.h

#ifndef _GUIMANAGER_H_
    #define _GUIMANAGER_H_
 
#include <OISMouse.h>
#include <SdkTrays.h>

class GUIManager{
    private:
        OgreBites::SdkTrayManager *mTrayMgr;
        OgreBites::ProgressBar* pb;
        bool main;
        bool mPause;
    public:
        GUIManager();
        ~GUIManager();
        void setup(OgreBites::SdkTrayManager* trayMgr);
        void begin_MainScreen();
        void end_MainScreen();
        bool inMainScreen();
        void begin_NumberOfEnemies();
        void updateNumberOfEnemies(int num);
        void end_NumberOfEnemies();
        void begin_MultiplayerScreen();
        void end_MultiplayerScreen();
        void pause();
        bool isPaused();
        bool isDialogVisible();
        void frameRenderingQueued(const Ogre::FrameEvent& evt);
        void hasBall();
        void threwBall();
        int createPowerBar();
        void destroyPowerBar();
        bool hasPowerBar();
        void nextRoundScreen(char* winner);
        void endGame(char* winner);
        void end_nextRoundScreen();
        void setPowerBarProgress(Ogre::Real power);
        static GUIManager GUIControl;
};

#endif
