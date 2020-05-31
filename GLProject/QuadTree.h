#pragma once
#include "Coordinate.h"
#include "Sensor.h"
namespace data {
	namespace tree {

		enum class TREETYPE
		{
			UPPERRIGHT, UPPERLEFT, LOWERRIGHT, LOWERLEFT, ORIGIN
		};

		struct AreasScanned
		{
			bool upperLeft = false;
			bool lowerLeft = false;
			bool upperRight = false;
			bool lowerRight = false;
		};

		class QuadTree
		{
			//----------------------------------------------------------------- PUBLIC
		public:
			//----------------------------------------------------- M�thodes publiques

			std::vector<Sensor*> searchPoint(const Coordinate& p, const double& area)const;

			const Coordinate& getUpperLeft()const;
			Coordinate getLowerLeft()const;
			Coordinate getUpperRight()const;
			Coordinate getLowerRight()const;

			//------------------------------------------------- Surcharge d'op�rateurs

			//-------------------------------------------- Constructeurs - destructeur
			QuadTree(const QuadTree& aTree);
			QuadTree();
			QuadTree(const QuadTree* myParent, const TREETYPE& tType);
			QuadTree(const Coordinate& mPos, const int& mSize, const std::vector<Sensor*>& mData);
			QuadTree(const std::vector<Sensor*>& mData);

			virtual ~QuadTree();

			//------------------------------------------------------------------ PRIVE
		protected:
			//----------------------------------------------------- M�thodes prot�g�es
			void loadOriginTree(const Coordinate& mPos, const int& mSize, const std::vector<Sensor*>& mData);
			const std::vector<Sensor*>& searchPointWithoutCheck(const Coordinate& p, const double& area, const TREETYPE& quadrant,AreasScanned& areas)const;
			//----------------------------------------------------- Attributs prot�g�s
			TREETYPE type;
			const QuadTree* parent;
			QuadTree* upperLeft;
			QuadTree* upperRight;
			QuadTree* lowerLeft;
			QuadTree* lowerRight;
			int quadSize;
			Coordinate position;
			std::vector<Sensor*> data;
		};
	}
}

