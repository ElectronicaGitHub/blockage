#include "HelloWorldScene.h"
#include "MovementComponent.h"
using namespace std;

USING_NS_CC;

Scene* HelloWorld::createScene() {
    auto scene = Scene::create();
    auto layer = HelloWorld::create();
    scene->addChild(layer);
    
    return scene;
}
bool HelloWorld::init() {
    if ( !Layer::init() ) {
        return false;
    }
    
    Entity* entity1 = new Entity("aaaa", vector<MainComponent *>{ new MovementComponent(pair<int, int>(10,10)) } );
    
    EntityManager::AddComponentToEntity(entity1, new MovementComponent(pair<int, int>(20, 20)));

    
    this->scheduleUpdate();
    return true;
}

void HelloWorld::update(float delta) {

}



