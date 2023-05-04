#include "ObjectManager.h"
#include "Object.h"

SINGLETON_INIT(ObjectManager)

ObjectManager::ObjectManager() {}

 Object* ObjectManager::GetFromIndexToObject(int& index)
 { 
	 if (_objectList[index] == nullptr)
	 {
		 RemoveFromIndexToObject(index);
		 --index;
		 return nullptr;
	 }

	 return _objectList[index]; 
 }


 void ObjectManager::Update()
 {
	 for (int i = 0; i < _objectList.size(); ++i)
	 {
		 if (_objectList[i]->GetIsDie())
		 {
			 delete _objectList[i];
 			 RemoveFromIndexToObject(i);
			 --i;
		 }

		 _objectList[i]->ObjUpdate();

	 }
	 for (int i = 0; i < _objectList.size(); ++i)
	 {
		 _objectList[i]->Render();
	 }
 }
