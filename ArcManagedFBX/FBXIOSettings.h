#pragma once
#include "FBXObject.h"

using namespace System;
using namespace System::Text;

using namespace ArcManagedFBX;

namespace ArcManagedFBX
{
	namespace IO
	{
		public ref class FBXIOSettings : public FBXObject
		{
		public:
			ARC_DEFAULT_CONSTRUCTORS(FBXIOSettings)

			ARC_FBX_FBXOBJECT_IMPLEMENT(FBXIOSettings,FBXObject)

			bool	GetBoolProp(String^pName, bool pDefValue);

			void	SetBoolProp(String^ pName, bool pValue);

			double	GetDoubleProp(String^ pName, double pDefValue);

			void	SetDoubleProp(String^ pName, double pValue);

			int		GetIntProp(String^ pName, int pDefValue);

			void	SetIntProp(String^ pName, int pValue);
		private:

		internal:
			ARC_CHILD_CAST(NativeObject,FbxIOSettings,FBXIOSettings)
			ARC_DEFAULT_INTERNAL_CONSTRUCTOR(FBXIOSettings,FbxIOSettings)
		};
	}
}