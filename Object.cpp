
#include "MyMotionState.cpp"

class Object { 
protected: 
	
	Ogre::Entity *ent;
	
	btCollisionShape* colShape;
	btScalar mass;
	MyMotionState* motionState;
	btVector3 startPos;
	
	

public: 
	Ogre::SceneNode* node; 
	Object(Ogre::SceneManager* scnMgr){}
	btRigidBody* body;

	btVector3 startVel;

	~Object(){}
	int color;
	Ogre::SceneNode* getNode() { return node; } 

	btRigidBody* getRigidBody(){return body;}

	btCollisionShape* getCollisionShape() { return colShape; }

	bool isDynamic() { return (mass != 0.f); }

	MyMotionState* getMotionState(){return motionState;}

	int speed;

	void reset(){
		clearForce();
		
		btTransform transform;
		transform.setIdentity();

		transform.setOrigin(startPos);

		body->setWorldTransform(transform);
		motionState->setWorldTransform(transform);
	}

	void clearForce(){
		btVector3 zeroVector(0, 0, 0);

		body->clearForces();
		body->setLinearVelocity(zeroVector);
		body->setAngularVelocity(zeroVector);
	}

	int getColor(){ return color;}

};
