#include "HelloWorldScene.h"

using namespace std;

USING_NS_CC;

Scene* HelloWorld::createScene() {
    auto scene = Scene::createWithPhysics();
    scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
    scene->getPhysicsWorld()->setGravity(Vect(0, -200));
    
    auto layer = HelloWorld::create();
    
    scene->addChild(layer);
    
    return scene;
}
bool HelloWorld::init() {
    if ( !Layer::init() ) {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
//    EntityManager entityManagerStatic;
    entityManager = new EntityManager(this);
    MapStorage mapStorage;
    imageStorage = new ImageStorage();
    
    // create screen boundary
    
    auto edgeNode = Node::create();
//    auto edgeBody = PhysicsBody::createEdgeBox(visibleSize, PHYSICSBODY_MATERIAL_DEFAULT, 3);
    
//    edgeNode->setPhysicsBody(edgeBody);
    edgeNode->setPosition(Point(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

    this->addChild(edgeNode);
    // screen boundary ended
    
    Entity* entity1 = new Entity("dwarf", vector<MainComponent *> {
        new MotionComponent(0, 0, 1.4, 10),
        new RenderComponent(this,
                            imageStorage->getImage("dwarf"),
                            pair<float, float>(200, 200),
                            pair<float, float>(20, 20),
                            "sprite"),
        new PositionComponent(200, 200, 1),
        new GravityComponent(),
        new ControlsComponent(),
        new JumpingComponent(),
        new ActiveCollisionComponent("player", {"player", "block"}),
        new RangedAttackComponent(30.0f, 10)
    });
    
    int mapSizeX = mapStorage.map[0].size();
    int mapSizeY = mapStorage.map.size();
    
    float fullsizeWidth = visibleSize.width;
    float fullsizeHeight = visibleSize.height;
    
    cout << "fullsizeWidth: " << fullsizeWidth << " and fullsizeHeight: " << fullsizeHeight << endl;
    cout << "mapSizeX: " << mapSizeX << " and mapSizeY: " << mapSizeY << endl;

    for (int i = 0; i < mapStorage.map.size(); i++) {
        for (int j = 0; j < mapStorage.map[i].size(); j++) {
            string id = "brick" + to_string(i) + "::" + to_string(j) + "";
            if (mapStorage.map[i][j]) {
                Entity* ent = new Entity(id, vector<MainComponent *> {
                    new RenderComponent(
                                        this,
                                        imageStorage->getImage("wall"),
                                        pair<float, float>(fullsizeWidth/mapSizeX * j + fullsizeWidth/mapSizeX/2 + origin.x, fullsizeHeight/mapSizeY * i + fullsizeWidth/mapSizeX/2),
                                        pair<float, float>(fullsizeWidth/mapSizeX, fullsizeHeight/mapSizeY),
                                        "node"),
                   new PassiveCollisionComponent()
                });
                entityManager->addEntity(ent);
            }
        }
    }
    
    entityManager->addEntity(entity1);

    UserActionsController(_eventDispatcher, this, entityManager);
    
    this->scheduleUpdate();
    return true;
}

void HelloWorld::update(float delta) {
    MotionController motionController;
    RangedAttackController rangedAttackController;
    RenderController renderController;
    CollisionController collisionController;
    
    motionController.tick(entityManager, delta);
    rangedAttackController.tick(entityManager, imageStorage, delta);
    renderController.tick(entityManager, delta);
    collisionController.tick(entityManager);
}