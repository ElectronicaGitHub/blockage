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
    
    Entity* dwarf = new Entity("dwarf", vector<MainComponent *> {
        new MotionComponent(0, 0, 150),
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
        new RangedAttackComponent(30.0f, 10),
        new DragAndCarryComponent()
    });
    
    int mapSizeX = mapStorage.map[0].size();
    int mapSizeY = mapStorage.map.size();
    
    float fullsizeWidth = visibleSize.width;
    float fullsizeHeight = visibleSize.height;
    
    map<string,int> tileSize = {
        {"x", round(fullsizeWidth/mapSizeX) },
        {"y", round(fullsizeHeight/mapSizeY) }
    };
    
    cout << "fullsizeWidth: " << fullsizeWidth << " and fullsizeHeight: " << fullsizeHeight << endl;
    cout << "mapSizeX: " << mapSizeX << " and mapSizeY: " << mapSizeY << endl;
    
    for (auto i = 0; i < 6; ++i) {
        string id = "droppable::" + to_string(i);
        Entity* dragBlock = new Entity(id, vector<MainComponent *> {
            new RenderComponent(this,
                                imageStorage->getImage("wall_draggable"),
                                pair<float, float>(100 * i, 100),
                                pair<float, float>(tileSize["x"], tileSize["y"]),
                                "sprite"),
            new PositionComponent(100 * i, 100, 1),
            new GravityComponent(),
            new PassiveCollisionComponent(),
            new DraggableComponent()
        });
        entityManager->addEntity(dragBlock);
    }

    for (int i = 0; i < mapStorage.map.size(); i++) {
        for (int j = 0; j < mapStorage.map[i].size(); j++) {
            string id = "brick" + to_string(i) + "::" + to_string(j) + "";
            if (mapStorage.map[i][j] == 1) {
                Entity* ent = new Entity(id, vector<MainComponent *> {
                    new RenderComponent(
                                        this,
                                        imageStorage->getImage("wall"),
                                        pair<float, float>(tileSize["x"] * j + tileSize["x"]/2 + origin.x, tileSize["y"] * i + tileSize["x"]/2 + origin.y),
                                        pair<float, float>(tileSize["x"], tileSize["y"]),
                                        "node"),
                    new PassiveCollisionComponent()
                });
                entityManager->addEntity(ent);
                
            } else if (mapStorage.map[i][j] == 2) {
                Entity* ent = new Entity(id, vector<MainComponent *> {
                    new RenderComponent(
                                        this,
                                        imageStorage->getImage("wall_transparent"),
                                        pair<float, float>(tileSize["x"] * j + tileSize["x"]/2 + origin.x, tileSize["y"] * i + tileSize["x"]/2 + origin.y),
                                        pair<float, float>(tileSize["x"], tileSize["y"]),
                                        "node"),
                    new DropComponent(),
                    new PositionComponent(tileSize["x"] * j + tileSize["x"]/2 + origin.x, tileSize["y"] * i + tileSize["x"]/2 + origin.y, 1)
                });
                entityManager->addEntity(ent);
            }
        }
    }
    
    entityManager->addEntity(dwarf);
    
    UserActionsController(_eventDispatcher, this, entityManager);
    
    this->scheduleUpdate();
    return true;
}

void HelloWorld::update(float delta) {
    MotionController motionController;
    RangedAttackController rangedAttackController;
    RenderController renderController;
    CollisionController collisionController;
    DragAndCarryController dragAndCarryController;
    
    motionController.tick(entityManager, delta);
    rangedAttackController.tick(entityManager, imageStorage, delta);
    dragAndCarryController.tick(entityManager);
    renderController.tick(entityManager, delta);
    collisionController.tick(entityManager);
}