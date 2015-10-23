#pragma once

#include "FBXTypes.h"
#include "FBXEmitter.h"

using namespace System;
using namespace System::Text;
using namespace ArcManagedFBX;

namespace ArcManagedFBX
{
	// Fuck yeah forward declar-- oh god why ;___;
	ref class FBXDocument;
	ref class FBXScene;
	ref class FBXManager;

	// The fbx object within the document that we are working with
	public ref class FBXObject : public FBXEmitter, public IDisposable
	{
	public:
		FBXObject();
		
		// The manager instance.
		FBXObject(FBXManager^ managerInstance, String^ objectName);
		
		virtual ~FBXObject();
		
		!FBXObject();
		ARC_FBX_FBXOBJECT_IMPLEMENT(FBXObject,FBXEmitter)

		virtual void SetSelected(bool pSelected);

		virtual bool GetSelected();

		const FBXManager^ GetManager();
		
		const FBXDocument^ GetDocument();
		
		const FBXDocument^ GetRootDocument();
		
		const FBXScene^ GetScene();
		
		void SetAllObjectFlags(uint32 flags);
		uint32 GetAllObjectFlags();

		// Wrapping the relevant objects for this
		int GetReferencedByCount();
		FBXObject^ GetReferencedBy(int32 index);

		void ResetProperties();

		void Destroy(bool recursive);

		const String^ GetInitialName();
		
		const String^ GetName();
		void SetName(String^ name);
		
		const String^ GetNameSpaceOnly();
		
		const String^ GetNameOnly();
		
		const String^ GetNameSpacePrefix();

		const uint64 GetUniqueID();

		generic<class ObjectType> where ObjectType : FBXObject, gcnew()
		ObjectType GetSrcObject(int32 index);

		// Check whether the source object is connected
		ARC_INLINE bool IsConnectedSrcObject(FBXObject^ other);
		ARC_INLINE bool DisconnectSrcObject(FBXObject^ other);

	protected:
		FbxObject* m_NativeObject;

	private:
		FBXManager^ m_ManagerInstance;
		
	internal:
		ARC_CHILD_CAST(NativeObject,FbxObject,FBXObject);
		FBXObject(FbxObject* objectInstance);
	
		FbxObject* GetObjectInstance();
	};
}