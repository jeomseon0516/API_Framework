#include "ObjectManager.h"

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
		 _objectList[i]->ObjUpdate();

		 if (_objectList[i]->GetIsDie())
		 {
			 delete _objectList[i];
			 RemoveFromIndexToObject(i);
			 --i;
		 }
	 }
	 for (int i = 0; i < _objectList.size(); ++i)
	 {
		 _objectList[i]->Render();
	 }
 }

 void ObjectManager::PushBackObject(Object* object)
 {
	 _objectList.push_back(object);
 }
