/*
-----------------------------------------------------------------------------
Filename: DodgeBall.cpp
-----------------------------------------------------------------------------
This source file is part of the
___ __ __ _ _ _
/___\__ _ _ __ ___ / / /\ \ (_) | _(_)
// // _` | '__/ _ \ \ \/ \/ / | |/ / |
/ \_// (_| | | | __/ \ /\ /| | <| |
\___/ \__, |_| \___| \/ \/ |_|_|\_\_|
|___/
Tutorial Framework
http://www.ogre3d.org/tikiwiki/
-----------------------------------------------------------------------------
*/
#include "DodgeBall.h"

//Simulator* simulator;
btDiscreteDynamicsWorld* world;
int mNumberOfEnemies = 7;
int mNumberOfBalls = 7;
int mNumberOfWins = 3;

bool DodgeBall::go(void)
{
    mShutDown=false;
    mRoundOver = false;
    playerwins=0;
    enemywins = 0;

#ifdef _DEBUG
    mResourcesCfg = "resources_d.cfg";
    mPluginsCfg = "plugins_d.cfg";
#else
    mResourcesCfg = "resources.cfg";
    mPluginsCfg = "plugins.cfg";
#endif
 
    // construct Ogre::Root
    mRoot = new Ogre::Root(mPluginsCfg);
 
//-------------------------------------------------------------------------------------
    // set up resources
    // Load resource paths from config file
    Ogre::ConfigFile cf;
    cf.load(mResourcesCfg);
 
    // Go through all sections & settings in the file
    Ogre::ConfigFile::SectionIterator seci = cf.getSectionIterator();
 
    Ogre::String secName, typeName, archName;
    while (seci.hasMoreElements())
    {
        secName = seci.peekNextKey();
        Ogre::ConfigFile::SettingsMultiMap *settings = seci.getNext();
        Ogre::ConfigFile::SettingsMultiMap::iterator i;
        for (i = settings->begin(); i != settings->end(); ++i)
        {
            typeName = i->first;
            archName = i->second;
            Ogre::ResourceGroupManager::getSingleton().addResourceLocation(
                archName, typeName, secName);
        }
    }

//-------------------------------------------------------------------------------------
    // configure
    // Show the configuration dialog and initialise the system
    // You can skip this and use root.restoreConfig() to load configuration
    // settings if you were sure there are valid ones saved in ogre.cfg
    if(mRoot->restoreConfig() || mRoot->showConfigDialog())
    {
        // If returned true, user clicked OK so initialise
        // Here we choose to let the system create a default rendering window by passing 'true'
        mWindow = mRoot->initialise(true, "DodgeBall Render Window");
    }
    else
    {
        return false;
    }
//-------------------------------------------------------------------------------------
    // choose scenemanager
    // Get the SceneManager, in this case a generic one
    mSceneMgr = mRoot->createSceneManager(Ogre::ST_GENERIC);

//-------------------------------------------------------------------------------------
    // Set default mipmap level (NB some APIs ignore this)
    Ogre::TextureManager::getSingleton().setDefaultNumMipmaps(5);
//-------------------------------------------------------------------------------------
    // Create any resource listeners (for loading screens)
    //createResourceListener();
//-------------------------------------------------------------------------------------
    // load resources
    Ogre::ResourceGroupManager::getSingleton().initialiseAllResourceGroups();
//-------------------------------------------------------------------------------------
    // set up physics
	//simulator = new Simulator();
	//Simulator::Simulation()/*simulator*/
	world = Simulator::Simulation.setupSimulator();
//-------------------------------------------------------------------------------------

    //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!Create Player/Enemy/Ball
    mSceneMgr->setShadowTechnique(Ogre::SHADOWTYPE_STENCIL_ADDITIVE);
    PlayerManager::PlayerControl.addPlayer(new Player(mSceneMgr, "Player1", 0, 200,PlayerManager::PlayerControl.player_size()));
    PlayerManager::PlayerControl.addEnemy(new Enemy(mSceneMgr, 0, 0, -200,PlayerManager::PlayerControl.enemy_size()));
    BallManager::BallControl.addBall(new Ball(mSceneMgr, &Simulator::Simulation/*simulator*/, "Ball", -20,BallManager::BallControl.size()));
//-------------------------------------------------------------------------------------
    // create viewports
    // Create one viewport, entire window
    Ogre::Viewport* vp = mWindow->addViewport(mSceneMgr->getCamera("Player1Cam"));
    vp->setBackgroundColour(Ogre::ColourValue(0,0,0));
 
    // Alter the camera aspect ratio to match the viewport
    mSceneMgr->getCamera("Player1Cam")->setAspectRatio(
    Ogre::Real(vp->getActualWidth()) / Ogre::Real(vp->getActualHeight()));

//-------------------------------------------------------------------------------------
    // Create the scene
 
    // Set ambient light
    mSceneMgr->setAmbientLight(Ogre::ColourValue(0.5, 0.5, 0.5));
 
    // Create a light
    Ogre::Light* l = mSceneMgr->createLight("MainLight");
    l->setPosition(20,80,50);
//-------------------------------------------------------------------------------------
    //create FrameListener
    Ogre::LogManager::getSingletonPtr()->logMessage("*** Initializing OIS ***");
    OIS::ParamList pl;
    size_t windowHnd = 0;
    std::ostringstream windowHndStr;
 
    mWindow->getCustomAttribute("WINDOW", &windowHnd);
    windowHndStr << windowHnd;
    pl.insert(std::make_pair(std::string("WINDOW"), windowHndStr.str()));
 
    mInputManager = OIS::InputManager::createInputSystem( pl );
 
    mKeyboard = static_cast<OIS::Keyboard*>(mInputManager->createInputObject( OIS::OISKeyboard, true ));
    mMouse = static_cast<OIS::Mouse*>(mInputManager->createInputObject( OIS::OISMouse, true ));
 
    mMouse->setEventCallback(this);
    mKeyboard->setEventCallback(this);
 
    //Set initial mouse clipping size
    windowResized(mWindow);
 
    //Register as a Window listener
    Ogre::WindowEventUtilities::addWindowEventListener(mWindow, this);
 
    mTrayMgr = new OgreBites::SdkTrayManager("InterfaceName", mWindow, mMouse, this);
    GUIManager::GUIControl.setup(mTrayMgr);
    
 

/////////////////////////////////////////////////////////////////////////////////// WALLS YAY
    Ogre::Plane roofFront(Ogre::Vector3::NEGATIVE_UNIT_Y, -100);
    Ogre::Plane roofBack(Ogre::Vector3::UNIT_Y, 100);
    Ogre::Plane floorFront(Ogre::Vector3::UNIT_Y, -100);
    Ogre::Plane floorBack(Ogre::Vector3::NEGATIVE_UNIT_Y, 100);
    Ogre::Plane rightWallFront(Ogre::Vector3::NEGATIVE_UNIT_X, -300);
    Ogre::Plane rightWallBack(Ogre::Vector3::UNIT_X, 300);
    Ogre::Plane leftWallFront(Ogre::Vector3::UNIT_X, -300);
    Ogre::Plane leftWallBack(Ogre::Vector3::NEGATIVE_UNIT_X, 300);
    Ogre::Plane frontWallFront(Ogre::Vector3::UNIT_Z, -300);
    Ogre::Plane frontWallBack(Ogre::Vector3::NEGATIVE_UNIT_Z, 300);
    Ogre::Plane backWallFront(Ogre::Vector3::NEGATIVE_UNIT_Z, -300);
    Ogre::Plane backWallBack(Ogre::Vector3::UNIT_Z, 300);

    
    Ogre::MeshManager::getSingleton().createPlane("roofFront", Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME,
    roofFront, 600, 600, 20, 20, true, 1, 5, 5, Ogre::Vector3::UNIT_Z);
    Ogre::MeshManager::getSingleton().createPlane("roofBack", Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME,
    roofBack, 600, 600, 20, 20, true, 1, 5, 5, Ogre::Vector3::UNIT_Z);
    Ogre::MeshManager::getSingleton().createPlane("floorFront", Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME,
    floorFront, 600, 600, 20, 20, true, 1, 5, 5, Ogre::Vector3::UNIT_Z);
    Ogre::MeshManager::getSingleton().createPlane("floorBack", Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME,
    floorBack, 600, 600, 20, 20, true, 1, 5, 5, Ogre::Vector3::UNIT_Z);
    Ogre::MeshManager::getSingleton().createPlane("rightWallFront", Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME,
    rightWallFront, 600, 200, 20, 20, true, 1, 5, 5, Ogre::Vector3::UNIT_Y);
    Ogre::MeshManager::getSingleton().createPlane("rightWallBack", Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME,
    rightWallBack, 600, 200, 20, 20, true, 1, 5, 5, Ogre::Vector3::UNIT_Y);
    Ogre::MeshManager::getSingleton().createPlane("leftWallFront", Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME,
    leftWallFront, 600, 200, 20, 20, true, 1, 5, 5, Ogre::Vector3::UNIT_Y);
    Ogre::MeshManager::getSingleton().createPlane("leftWallBack", Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME,
    leftWallBack, 600, 200, 20, 20, true, 1, 5, 5, Ogre::Vector3::UNIT_Y);
    Ogre::MeshManager::getSingleton().createPlane("frontWallFront", Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME,
    frontWallFront, 200, 200, 20, 20, true, 1, 5, 5, Ogre::Vector3::UNIT_X);
    Ogre::MeshManager::getSingleton().createPlane("frontWallBack", Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME,
    frontWallBack, 200, 200, 20, 20, true, 1, 5, 5, Ogre::Vector3::UNIT_X);
    Ogre::MeshManager::getSingleton().createPlane("backWallFront", Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME,
    backWallFront, 200, 200, 20, 20, true, 1, 5, 5, Ogre::Vector3::UNIT_X);
    Ogre::MeshManager::getSingleton().createPlane("backWallBack", Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME,
    backWallBack, 200, 200, 20, 20, true, 1, 5, 5, Ogre::Vector3::UNIT_X);
    

    Ogre::Entity* entFrontWallFront = mSceneMgr->createEntity("FrontWallFront", "frontWallFront");
    mSceneMgr->getRootSceneNode()->createChildSceneNode()->attachObject(entFrontWallFront);
    entFrontWallFront->setMaterialName("Examples/Rockwall");
    entFrontWallFront->setCastShadows(false);

    Ogre::Entity* entFrontWallBack = mSceneMgr->createEntity("FrontWallBack", "frontWallBack");
    mSceneMgr->getRootSceneNode()->createChildSceneNode()->attachObject(entFrontWallBack);
    entFrontWallBack->setMaterialName("Examples/Rockwall");
    entFrontWallBack->setCastShadows(false);

    Ogre::Entity* entBackWallFront = mSceneMgr->createEntity("BackWallFront", "backWallFront");
    mSceneMgr->getRootSceneNode()->createChildSceneNode()->attachObject(entBackWallFront);
    entBackWallFront->setMaterialName("Examples/Rockwall");
    entBackWallFront->setCastShadows(false);

    Ogre::Entity* entBackWallBack = mSceneMgr->createEntity("BackWallBack", "backWallBack");
    mSceneMgr->getRootSceneNode()->createChildSceneNode()->attachObject(entBackWallBack);
    entBackWallBack->setMaterialName("Examples/Rockwall");
    entBackWallBack->setCastShadows(false);

    
    Ogre::Entity* entRoofFront = mSceneMgr->createEntity("RoofFrontEntity", "roofFront");
    mSceneMgr->getRootSceneNode()->createChildSceneNode()->attachObject(entRoofFront);
    entRoofFront->setMaterialName("Examples/Rockwall");
    entRoofFront->setCastShadows(false);

    Ogre::Entity* entRoofBack = mSceneMgr->createEntity("RoofBackEntity", "roofBack");
    mSceneMgr->getRootSceneNode()->createChildSceneNode()->attachObject(entRoofBack);
    entRoofBack->setMaterialName("Examples/Rockwall");
    entRoofBack->setCastShadows(false);

    Ogre::Entity* entFloorFront = mSceneMgr->createEntity("FloorFrontEntity", "floorFront");
    mSceneMgr->getRootSceneNode()->createChildSceneNode()->attachObject(entFloorFront);
    entFloorFront->setMaterialName("Examples/Rockwall");
    entFloorFront->setCastShadows(false);

    Ogre::Entity* entFloorBack = mSceneMgr->createEntity("FloorBackEntity", "floorBack");
    mSceneMgr->getRootSceneNode()->createChildSceneNode()->attachObject(entFloorBack);
    entFloorBack->setMaterialName("Examples/Rockwall");
    entFloorBack->setCastShadows(false);

    Ogre::Entity* entRightWallFront = mSceneMgr->createEntity("RightWallFront", "rightWallFront");
    mSceneMgr->getRootSceneNode()->createChildSceneNode()->attachObject(entRightWallFront);
    entRightWallFront->setMaterialName("Examples/Rockwall");
    entRightWallFront->setCastShadows(false);

    Ogre::Entity* entRightWallBack = mSceneMgr->createEntity("RightWallBack", "rightWallBack");
    mSceneMgr->getRootSceneNode()->createChildSceneNode()->attachObject(entRightWallBack);
    entRightWallBack->setMaterialName("Examples/Rockwall");
    entRightWallBack->setCastShadows(false);

    Ogre::Entity* entLeftWallFront = mSceneMgr->createEntity("LefttWallFront", "leftWallFront");
    mSceneMgr->getRootSceneNode()->createChildSceneNode()->attachObject(entLeftWallFront);
    entLeftWallFront->setMaterialName("Examples/Rockwall");
    entLeftWallFront->setCastShadows(false);

    Ogre::Entity* entLeftWallBack = mSceneMgr->createEntity("LeftWallBack", "leftWallBack");
    mSceneMgr->getRootSceneNode()->createChildSceneNode()->attachObject(entLeftWallBack);
    entLeftWallBack->setMaterialName("Examples/Rockwall");
    entLeftWallBack->setCastShadows(false);

    //-------------------------------------------------------------------------------------
    //load Sounds
    SDL_InitSubSystem(SDL_INIT_AUDIO);

    if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 4096) < 0)
        return false;

     Mix_AllocateChannels(32); 
    
    if((ballBounceWall = SoundManager::SoundControl.loadWAV("sound/slap2.wav")) == -1)
        return false;
    if((ballPlayerHit = SoundManager::SoundControl.loadWAV("sound/slap1.wav")) == -1)
        return false;
    if((ballPlayerThrow = SoundManager::SoundControl.loadWAV("sound/sword_hit_single2.wav")) == -1)
        return false;


    SoundManager::SoundControl.setup(ballBounceWall, ballPlayerHit, ballPlayerThrow);
    music = Mix_LoadMUS("sound/risveglio.wav");
    Mix_PlayMusic(music, -1);
    Mix_Volume(-1,MIX_MAX_VOLUME/6);
    SoundManager::SoundControl.pauseAudio();
    
    //---------------------------------------------------------------------------------
    mPause = false;
    mGameOver = false;

    mRoot->addFrameListener(this);
//-------------------------------------------------------------------------------------
    mRoot->startRendering();
 
    return true;
}
bool DodgeBall::frameRenderingQueued(const Ogre::FrameEvent& evt)
{

    if(mWindow->isClosed())
        return false;

    if(mShutDown)
        return false;

    //Need to capture/update each device
    mKeyboard->capture();
    mMouse->capture();

    if(mPause || mRoundOver)
        return true;

    if(playerwins>=mNumberOfWins)
    {
        GUIManager::GUIControl.endGame("Player Team Wins!");
        mPause = true;
        mGameOver = true;
        return true;
    }else if(enemywins>=mNumberOfWins)
    {
        GUIManager::GUIControl.endGame("Player Team Lost :-(");
        mPause = true;
        mGameOver = true;
        return true;
    }

    if(PlayerManager::PlayerControl.enemiesLeft()==0 && !mGameOver)
    {
		GUIManager::GUIControl.nextRoundScreen("Player Team Wins");
		playerwins++;
		mRoundOver=true;
		//Player team wins!
    }
    else if(PlayerManager::PlayerControl.playersLeft()==0 && !mGameOver)
    {
		GUIManager::GUIControl.nextRoundScreen("Enemy Team Wins");
		enemywins++;
		mRoundOver=true;
		//Enemy team wins!
    }

	Player* player;
    for(int i = 0; i < PlayerManager::PlayerControl.player_size(); i++){
        player = PlayerManager::PlayerControl.getPlayer(i);
		if(!player->isInPlay())
			continue;
        player->move(evt);
        if(player->isThrowing())
            player->chargeThrow();
    }
    Enemy* enemy;
    for(int i = 0; i < PlayerManager::PlayerControl.enemy_size(); i++){
        enemy = PlayerManager::PlayerControl.getEnemy(i);
		if(!enemy->isInPlay())
		{
			continue;
		}
        if(!enemy->hasBall()){
	        Ball* ball = BallManager::BallControl.getNearestBall(enemy->getPosition());
	 //       ball->setDanger(false);
		bool chase=false;
	        if(ball->isDangerous() <= 0 && PlayerManager::PlayerControl.isClosestEnemy(enemy->getPosition(), ball->getPosition()))
		{
            		chase=enemy->getNearBall(ball, evt);
		}	        
		if(!chase && ball->isDangerous() && ball->towardsPos(enemy->getPosition()))
		        enemy->getAwayBall(ball, evt);
		else if(!chase){
			enemy->randomMove();
		}
    //        for(int i = 0; i < BallManager::BallControl.size(); i++)   
   //             enemy->pickupBall(BallManager::BallControl.getBall(i));
        }else{
            enemy->beginThrow();
            enemy->endThrow(PlayerManager::PlayerControl.getPlayer(0)->getPosition());
        	SoundManager::SoundControl.playClip(ballPlayerThrow, 0);
		}
    }

    //printf("before step simulation\n");
    world->stepSimulation(1/60.0);
    //printf("after step simulation\n");
        
    BallManager::BallControl.updateBalls();

    mTrayMgr->frameRenderingQueued(evt);
 
    GUIManager::GUIControl.frameRenderingQueued(evt); 

    if (!GUIManager::GUIControl.isDialogVisible())
    {
      //if (GUIManager::GUIControl.isScoreboardVisible())   // if details panel is visible, then update its contents
      //{
        //GUIManager::GUIControl.inPlay(inPlay, effect, timer, score);
      //}
    }
 
    return true;
}

void DodgeBall::loadNextRound()
{
	//reset simulator (or else put balls into position again in simulator)
	//put player and balls back into position in ogre
	for(int i=0;i<PlayerManager::PlayerControl.player_size();i++)		//need to make players throw balls prior to resetting them
	{
		Player* p=PlayerManager::PlayerControl.getPlayer(i);
		p->respawn();
		p->setInPlay(true);
		if(p->hasBall())
		{
			p->extThrow(btVector3(0,0,0),5);
		}
		
	}
	for(int i=0;i<PlayerManager::PlayerControl.enemy_size();i++)		//need to make players throw balls prior to resetting them
	{
		Enemy* e=PlayerManager::PlayerControl.getEnemy(i);
		e->respawn();
		e->setInPlay(true);
		if(e->hasBall())
		{
			e->extThrow(btVector3(0,0,0),5);
		}
	}
	for(int i = 0; i < BallManager::BallControl.size(); i++)		//need to make players throw balls prior to resetting them
	{
        	BallManager::BallControl.getBall(i)->respawn();
	}
}

//-------------------------------------------------------------------------------------
bool DodgeBall::keyPressed( const OIS::KeyEvent &arg )
{
    if (GUIManager::GUIControl.isDialogVisible()) return true; // don't process any more keys if dialog is up


    else if(arg.key == OIS::KC_F5) // refresh all textures
    {
        Ogre::TextureManager::getSingleton().reloadAll();
    }
    Player* player;
    for(int i = 0; i < PlayerManager::PlayerControl.player_size(); i++){
        player = PlayerManager::PlayerControl.getPlayer(i);
        if(arg.key == OIS::KC_W) // refresh all textures
        {
            player->startMove("w");
        }
        else if(arg.key == OIS::KC_A) // refresh all textures
        {
            player->startMove("a");
        }
        else if(arg.key == OIS::KC_S) // refresh all textures
        {
            player->startMove("s");
        }
        else if(arg.key == OIS::KC_D) // refresh all textures
        {
            player->startMove("d");
        }
    }
    if (arg.key == OIS::KC_SYSRQ) // take a screenshot
    {
        mWindow->writeContentsToTimestampedFile("screenshot", ".jpg");
    }
    else if (arg.key == OIS::KC_ESCAPE && !mRoundOver)
    {
        GUIManager::GUIControl.pause();
        mPause = mPause ? false : true; 
    }
    return true;
}
 
bool DodgeBall::keyReleased( const OIS::KeyEvent &arg )
{
    Player* player;
    for(int i = 0; i < PlayerManager::PlayerControl.player_size(); i++){
        player = PlayerManager::PlayerControl.getPlayer(i);
        if(arg.key == OIS::KC_W) // refresh all textures
        {
            player->stopMove("w");
        }
        else if(arg.key == OIS::KC_A) // refresh all textures
        {
            player->stopMove("a");
        }
        else if(arg.key == OIS::KC_S) // refresh all textures
        {
            player->stopMove("s");
        }
        else if(arg.key == OIS::KC_D) // refresh all textures
        {
            player->stopMove("d");
        }
	else if(arg.key == OIS::KC_R) // refresh all textures
        {
		loadNextRound();
	/*	player->respawn();
		for(int i = 0; i < PlayerManager::PlayerControl.enemy_size(); i++){
        	PlayerManager::PlayerControl.getEnemy(i)->respawn();
	    	}
		for(int i = 0; i < BallManager::BallControl.size(); i++){		//need to make players throw balls prior to resetting them
        	BallManager::BallControl.getBall(i)->respawn();
	    	}*/
        }
    }
    return true;
}
 
bool DodgeBall::mouseMoved( const OIS::MouseEvent &arg )
{
    if (mTrayMgr->injectMouseMove(arg)) return true;
    if(!GUIManager::GUIControl.isPaused() && !mPause && !mRoundOver){
        for(int i = 0; i < PlayerManager::PlayerControl.player_size(); i++)
            PlayerManager::PlayerControl.getPlayer(i)->lookAround(arg);
    }
    return true;
}
 
bool DodgeBall::mousePressed( const OIS::MouseEvent &arg, OIS::MouseButtonID id )
{
    if (mTrayMgr->injectMouseDown(arg, id)) return true;
    if (mPause) return true;

    Player* player;
    for(int i = 0; i < PlayerManager::PlayerControl.player_size(); i++){
        player = PlayerManager::PlayerControl.getPlayer(i);
        if(player->hasBall())
            player->beginThrow();
    }
    return true;
}
 
bool DodgeBall::mouseReleased( const OIS::MouseEvent &arg, OIS::MouseButtonID id )
{
    if (mTrayMgr->injectMouseUp(arg, id)) return true;

    Player* player;
    for(int i = 0; i < PlayerManager::PlayerControl.player_size(); i++){
        player = PlayerManager::PlayerControl.getPlayer(i);
        if(player->hasBall()){
            player->endThrow();
            SoundManager::SoundControl.playClip(ballPlayerThrow, 0);
        }
    }
    return true;
}

void DodgeBall::buttonHit(OgreBites::Button* button){
    if (button->getName().compare("Exit") == 0 || button->getName().compare("PauseExit") == 0)
        mShutDown = true;
    else if(button->getName().compare("Resume") == 0){
        GUIManager::GUIControl.pause();
        mPause = false;
    }
    else if(button->getName().compare("Singleplayer") == 0){
        GUIManager::GUIControl.end_MainScreen();
        GUIManager::GUIControl.begin_NumberOfEnemies();
    }
    else if(button->getName().compare("+Enemies") == 0){
        if(mNumberOfEnemies < 20)
            mNumberOfEnemies++;
        GUIManager::GUIControl.updateNumberOfEnemies(mNumberOfEnemies);
    }
    else if(button->getName().compare("-Enemies") == 0){
        if(mNumberOfEnemies > 1)
            mNumberOfEnemies--;
        GUIManager::GUIControl.updateNumberOfEnemies(mNumberOfEnemies);
    }
    else if(button->getName().compare("NumberEnemiesContinue") == 0){
        GUIManager::GUIControl.end_NumberOfEnemies();
        int row1 = 1;
        int row2 = 0;
        for(int i = 1; i < mNumberOfEnemies; i++){
            if(i <=10){
                PlayerManager::PlayerControl.addEnemy(new Enemy(mSceneMgr, i, 0 + pow(-1.0, i) * (50 * row1), -200,PlayerManager::PlayerControl.enemy_size()));
                if(i % 2 == 0)
                    row1++;
            }
            else{
                PlayerManager::PlayerControl.addEnemy(new Enemy(mSceneMgr, i, 0 + pow(-1.0, i) * (50 * row2), -250,PlayerManager::PlayerControl.enemy_size()));
                if(i % 2 == 0)
                    row2++;
            }
        }
    }
    else if(button->getName().compare("+Balls") == 0){
        if(mNumberOfBalls < 20)
            mNumberOfBalls++;
        GUIManager::GUIControl.updateNumberOfBalls(mNumberOfBalls);
    }
    else if(button->getName().compare("-Balls") == 0){
        if(mNumberOfBalls > 1)
            mNumberOfBalls--;
        GUIManager::GUIControl.updateNumberOfBalls(mNumberOfBalls);
    }
    else if(button->getName().compare("NumberBallsContinue") == 0){
        GUIManager::GUIControl.end_NumberOfBalls();
        GUIManager::GUIControl.begin_NumberOfWins();
        for(int i = 1; i < mNumberOfBalls; i++)
            BallManager::BallControl.addBall(new Ball(mSceneMgr, &Simulator::Simulation, "Ball" + Ogre::StringConverter::toString(i), -80 + (50 * i),BallManager::BallControl.size()));
	}else if(button->getName().compare("+Wins") == 0){
        if(mNumberOfWins < 20)
            mNumberOfWins++;
        GUIManager::GUIControl.updateNumberOfWins(mNumberOfWins);
    }
    else if(button->getName().compare("-Wins") == 0){
        if(mNumberOfWins > 1)
            mNumberOfWins--;
        GUIManager::GUIControl.updateNumberOfWins(mNumberOfWins);
    }
    else if(button->getName().compare("NumberWinsContinue") == 0){
        GUIManager::GUIControl.end_NumberOfWins();
        SoundManager::SoundControl.playAudio();
    }else if(button->getName().compare("NextRound") == 0)
    {
        GUIManager::GUIControl.end_nextRoundScreen();
		loadNextRound();
		mPause=false;
        mRoundOver = false;
    }else if(button->getName().compare("Replay") == 0){
        enemywins = 0;
        playerwins = 0;
        mGameOver = false;
        mPause = false;
        mRoundOver = false;
        GUIManager::GUIControl.replay();
    }
    /*else if(button->getName().compare("MainMenu") == 0){
        GUIManager::GUIControl.pause();
        GUIManager::GUIControl.begin_MainScreen();
    }*/
}
 
//Adjust mouse clipping area
void DodgeBall::windowResized(Ogre::RenderWindow* rw)
{
    unsigned int width, height, depth;
    int left, top;
    rw->getMetrics(width, height, depth, left, top);
 
    const OIS::MouseState &ms = mMouse->getMouseState();
    ms.width = width;
    ms.height = height;
}
 
//Unattach OIS before window shutdown (very important under Linux)
void DodgeBall::windowClosed(Ogre::RenderWindow* rw)
{
    //Only close for window that created OIS (the main window in these demos)
    if( rw == mWindow )
    {
        if( mInputManager )
        {
            mInputManager->destroyInputObject( mMouse );
            mInputManager->destroyInputObject( mKeyboard );
 
            OIS::InputManager::destroyInputSystem(mInputManager);
            mInputManager = 0;
        }
    }
}
 
 
 
#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32
#define WIN32_LEAN_AND_MEAN
#include "windows.h"
#endif
 
#ifdef __cplusplus
extern "C" {
#endif
 
#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32
    INT WINAPI WinMain( HINSTANCE hInst, HINSTANCE, LPSTR strCmdLine, INT )
#else
    int main(int argc, char *argv[])
#endif
    {
        // Create application object
        DodgeBall app;
 
        try {
            app.go();
        } catch( Ogre::Exception& e ) {
#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32
            MessageBox( NULL, e.getFullDescription().c_str(), "An exception has occured!", MB_OK | MB_ICONERROR | MB_TASKMODAL);
#else
            std::cerr << "An exception has occured: " <<
                e.getFullDescription().c_str() << std::endl;
#endif
        }
 
        return 0;
    }
 
#ifdef __cplusplus
}
#endif
