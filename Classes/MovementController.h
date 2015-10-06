//
//  MovementController.h
//  cppTests
//
//  Created by Philip Antonov on 26.09.15.
//
//

//#ifndef __cppTests__MovementController__
//#define __cppTests__MovementController__
//
//#include <stdio.h>
//#include "EntityManager.h"
//#include "RenderComponent.h"
//#include "ControlsComponent.h"
//#include "MovementComponent.h"
//
//using namespace std;
//
//class MovementController {
//public:
//    MovementController() {};
//    ~MovementController() {};
//    
//    void tick() {
//        EntityManager entityManager;
//        vector<Entity*> entities = entityManager.GetAllEntitiesByComponentTypes({"MovementComponent", "ControlsComponent"});
//        
//        for (int i = 0; i < entities.size(); ++i) {
//            
//            ControlsComponent* control = static_cast<ControlsComponent* >(entityManager.GetComponentByTypeFromEntity(entities[i], "ControlsComponent"));
//            RenderComponent* render = static_cast<RenderComponent* >(entityManager.GetComponentByTypeFromEntity(entities[i], "RenderComponent"));
//            MovementComponent* movement = static_cast<MovementComponent* >(entityManager.GetComponentByTypeFromEntity(entities[i], "MovementComponent"));
//            
//            Vect velocity = render->spriteBody->getVelocity();
//            
//            bool moveLeft = control->keys[EventKeyboard::KeyCode::KEY_LEFT_ARROW] || control->keys[EventKeyboard::KeyCode::KEY_A];
//            bool moveRight = control->keys[EventKeyboard::KeyCode::KEY_RIGHT_ARROW] || control->keys[EventKeyboard::KeyCode::KEY_D];
//            bool moveUp = control->keys[EventKeyboard::KeyCode::KEY_UP_ARROW] || control->keys[EventKeyboard::KeyCode::KEY_W];
//            
//            if (moveLeft) {
//                Vect summary = velocity - Vect(movement->velocityDx, 0);
//                if (abs(summary.x) < movement->velocityMax) {
//                    render->spriteBody->setVelocity(summary);
//                }
//            }
//            if (moveRight) {
//                Vect summary = velocity + Vect(movement->velocityDx, 0);
//                if (abs(summary.x) < movement->velocityMax) {
//                    render->spriteBody->setVelocity(summary);
//                }
//            }
//            if (moveUp) {
//                if (!render->states["jump"]) {
//                                    cout << "moveUp" << endl;
//                    velocity.y += 100;
//                    render->spriteBody->setVelocity(velocity);
////                    render->states["jump"] = true;
//                }
//            }
////            if (control->keys[EventKeyboard::KeyCode::KEY_DOWN_ARROW] || control->keys[EventKeyboard::KeyCode::KEY_S]) {
////            }
//            
//            // затухание
//            int minus = velocity.x < 0 ? 1 : -1;
//            Vect summary = velocity + ((Vect(movement->velocityDensity, 0)) * minus);
//            
//            if (!moveRight && !moveLeft) {
//                if (abs(summary.x) <= movement->velocityDensity) {
//                    summary.x = 0;
//                }
//                render->spriteBody->setVelocity(summary);
//            }
//        }
//    }
//};
//
//#endif /* defined(__cppTests__MovementController__) */
