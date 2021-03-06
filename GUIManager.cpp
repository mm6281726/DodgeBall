//GUIManager.cpp

#include "GUIManager.h"

GUIManager GUIManager::GUIControl;

    GUIManager::GUIManager() :
    main(true),
    mPause(false),
    pb(NULL)
    {}

    GUIManager::~GUIManager() {
        mTrayMgr->destroyAllWidgets();
    }

    void GUIManager::setup(OgreBites::SdkTrayManager* trayMgr){
        mTrayMgr = trayMgr;
        mTrayMgr->hideCursor();

        begin_MainScreen();

        Ogre::FontManager::getSingleton().getByName("SdkTrays/Caption")->load();

    }

    void GUIManager::begin_MainScreen(){
        main = true;
        mTrayMgr->createLabel(OgreBites::TL_CENTER, "MainScreen", "NINJA DODGEBALL");
        mTrayMgr->createButton(OgreBites::TL_CENTER, "Singleplayer", "Play", 250);
        mTrayMgr->createButton(OgreBites::TL_CENTER, "Exit", "Exit", 250);
        mTrayMgr->showCursor();
        mTrayMgr->showBackdrop("Examples/Chrome");
    }

    void GUIManager::end_MainScreen(){
        mTrayMgr->destroyWidget("MainScreen");
        mTrayMgr->destroyWidget("Singleplayer");
        mTrayMgr->destroyWidget("Exit");
        mTrayMgr->hideBackdrop();
    }

    bool GUIManager::inMainScreen(){
        return main;
    }

    void GUIManager::begin_NumberOfEnemies(){
        mTrayMgr->createLabel(OgreBites::TL_CENTER, "NumberOfEnemies", "Number of Enemies");
        mTrayMgr->createLabel(OgreBites::TL_CENTER, "NOEnemies", "7");
        mTrayMgr->createButton(OgreBites::TL_CENTER, "+Enemies", "+", 250);
        mTrayMgr->createButton(OgreBites::TL_CENTER, "-Enemies", "-", 250);
        mTrayMgr->createButton(OgreBites::TL_CENTER, "NumberEnemiesContinue", "Continue", 250);
        mTrayMgr->createButton(OgreBites::TL_CENTER, "Exit", "Exit", 250);
        mTrayMgr->showBackdrop("Examples/Chrome");
    }

    void GUIManager::updateNumberOfEnemies(int num){
        OgreBites::Label* l = (OgreBites::Label*)mTrayMgr->getWidget("NOEnemies");
        l->setCaption(Ogre::StringConverter::toString(num));
    }

    void GUIManager::end_NumberOfEnemies(){
        main = false;
        mTrayMgr->destroyWidget("NumberOfEnemies");
        mTrayMgr->destroyWidget("NOEnemies");
        mTrayMgr->destroyWidget("+Enemies");
        mTrayMgr->destroyWidget("-Enemies");
        mTrayMgr->destroyWidget("NumberEnemiesContinue");
        mTrayMgr->destroyWidget("Exit");
        mTrayMgr->hideBackdrop();
        begin_NumberOfBalls();
    }

    void GUIManager::begin_NumberOfBalls(){
        mTrayMgr->createLabel(OgreBites::TL_CENTER, "NumberOfBalls", "Number of Balls");
        mTrayMgr->createLabel(OgreBites::TL_CENTER, "NOBalls", "10");
        mTrayMgr->createButton(OgreBites::TL_CENTER, "+Balls", "+", 250);
        mTrayMgr->createButton(OgreBites::TL_CENTER, "-Balls", "-", 250);
        mTrayMgr->createButton(OgreBites::TL_CENTER, "NumberBallsContinue", "Continue", 250);
        mTrayMgr->createButton(OgreBites::TL_CENTER, "Exit", "Exit", 250);
        mTrayMgr->showBackdrop("Examples/Chrome");
    }

    void GUIManager::updateNumberOfBalls(int num){
        OgreBites::Label* l = (OgreBites::Label*)mTrayMgr->getWidget("NOBalls");
        l->setCaption(Ogre::StringConverter::toString(num));
    }

    void GUIManager::end_NumberOfBalls(){
        main = false;
        mTrayMgr->destroyWidget("NumberOfBalls");
        mTrayMgr->destroyWidget("NOBalls");
        mTrayMgr->destroyWidget("+Balls");
        mTrayMgr->destroyWidget("-Balls");
        mTrayMgr->destroyWidget("NumberBallsContinue");
        mTrayMgr->destroyWidget("Exit");
    }

    void GUIManager::begin_NumberOfWins(){
        mTrayMgr->createLabel(OgreBites::TL_CENTER, "NumberOfWins", "First To How Many Wins?");
        mTrayMgr->createLabel(OgreBites::TL_CENTER, "NOWins", "3");
        mTrayMgr->createButton(OgreBites::TL_CENTER, "+Wins", "+", 250);
        mTrayMgr->createButton(OgreBites::TL_CENTER, "-Wins", "-", 250);
        mTrayMgr->createButton(OgreBites::TL_CENTER, "NumberWinsContinue", "Continue", 250);
        mTrayMgr->createButton(OgreBites::TL_CENTER, "Exit", "Exit", 250);
        mTrayMgr->showBackdrop("Examples/Chrome");
    }

    void GUIManager::updateNumberOfWins(int num){
        OgreBites::Label* l = (OgreBites::Label*)mTrayMgr->getWidget("NOWins");
        l->setCaption(Ogre::StringConverter::toString(num));
    }

    void GUIManager::end_NumberOfWins(){
        main = false;
        mTrayMgr->destroyWidget("NumberOfWins");
        mTrayMgr->destroyWidget("NOWins");
        mTrayMgr->destroyWidget("+Wins");
        mTrayMgr->destroyWidget("-Wins");
        mTrayMgr->destroyWidget("NumberWinsContinue");
        mTrayMgr->destroyWidget("Exit");
        mTrayMgr->hideCursor();
        mTrayMgr->hideBackdrop();
    }

    void GUIManager::nextRoundScreen(char* winner){
        mTrayMgr->createLabel(OgreBites::TL_CENTER, "RoundTransition",winner);
        mTrayMgr->createButton(OgreBites::TL_CENTER, "NextRound", "Next Round", 250);
        mTrayMgr->createButton(OgreBites::TL_CENTER, "Exit", "Quit", 250);
        mTrayMgr->showCursor();
    }

    void GUIManager::end_nextRoundScreen(){
        mTrayMgr->destroyWidget("RoundTransition");
        mTrayMgr->destroyWidget("NextRound");
        mTrayMgr->destroyWidget("Exit");
        mTrayMgr->hideCursor();
    }

    void GUIManager::endGame(char* winner){
        mTrayMgr->createLabel(OgreBites::TL_CENTER, "GameOver",winner);
        mTrayMgr->createButton(OgreBites::TL_CENTER, "Replay", "Replay", 250);
        mTrayMgr->createButton(OgreBites::TL_CENTER, "Exit", "Quit", 250);
        mTrayMgr->showCursor();
    }

    void GUIManager::pause(){
        if(!main){
        if(!mPause){
            mTrayMgr->showCursor();
            mTrayMgr->createLabel(OgreBites::TL_CENTER, "PauseScreen", "Pause");
            mTrayMgr->createButton(OgreBites::TL_CENTER, "Resume", "Resume", 250);
            //mTrayMgr->createButton(OgreBites::TL_CENTER, "MainMenu", "Main Menu", 250);
            mTrayMgr->createButton(OgreBites::TL_CENTER, "PauseExit", "Exit", 250);
            mPause = true;
        }else{
            mTrayMgr->hideCursor();
            mTrayMgr->destroyWidget("PauseScreen");
            mTrayMgr->destroyWidget("Resume");
            //mTrayMgr->destroyWidget("MainMenu");
            mTrayMgr->destroyWidget("PauseExit");
            mPause = false;
        }
    }
    }

    bool GUIManager::isPaused(){
        return mPause;
    }

    bool GUIManager::isDialogVisible(){
        return mTrayMgr->isDialogVisible();
    }

    void GUIManager::frameRenderingQueued(const Ogre::FrameEvent& evt){
        mTrayMgr->frameRenderingQueued(evt);
        mTrayMgr->adjustTrays();
    }

    void GUIManager::hasBall(){
        //mTrayMgr->createDecorWidget(OgreBites::TL_BOTTOMRIGHT, "hasBall", "Ogre");
        mTrayMgr->showLogo(OgreBites::TL_BOTTOMRIGHT);
    }

    void GUIManager::threwBall(){
        //mTrayMgr->destroyWidget("hasBall");
        mTrayMgr->hideLogo();
    }

    int GUIManager::createPowerBar(){
        pb = mTrayMgr->createProgressBar(OgreBites::TL_BOTTOM, "Power", "Power", 500, 500);
    }

    void GUIManager::destroyPowerBar(){
        if(pb != NULL){
            pb = NULL;
            mTrayMgr->destroyWidget("Power");
        }
    }

    bool GUIManager::hasPowerBar(){
        if(pb == NULL)
            return false;
        else return true;
    }

    void GUIManager::setPowerBarProgress(Ogre::Real power){
        pb->setProgress(power);
    }

    void GUIManager::replay(){
        mTrayMgr->destroyWidget("GameOver");
        mTrayMgr->destroyWidget("Replay");
        mTrayMgr->destroyWidget("Exit");
        mTrayMgr->hideCursor();
    }