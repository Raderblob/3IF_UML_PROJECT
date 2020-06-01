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
			//----------------------------------------------------- Méthodes publiques

			/**
			* Search for an area(Square) centered by a point with a certain width 
			*
			* @param p Center of the area
			* @param area width and height of the square
			*
			* @return All sensors withing the area
			*/
			std::vector<Sensor*> searchPoint(const Coordinate& p, const double& area)const;

			/// Returns upperLeft of Quad
			const Coordinate& getUpperLeft()const;

			/// Returns lowerLeft of Quad
			Coordinate getLowerLeft()const;

			/// Returns upperRight of Quad
			Coordinate getUpperRight()const;

			/// Returns lowerRight of Quad
			Coordinate getLowerRight()const;

			//------------------------------------------------- Surcharge d'opérateurs

			//-------------------------------------------- Constructeurs - destructeur

			/// not implemented
			QuadTree(const QuadTree& aTree);
			/// not implemented
			QuadTree();

			/**
			* Constructor for QuadTree
			*
			* @param myParent Cannot be null, pointer to the parent of the Quad
			* @param tType type of the Quad Tree
			* @see TREETYPE
			*
			*/
			QuadTree(const QuadTree* myParent, const TREETYPE& tType);

			/**
			* Constructor for QuadTree
			*
			* @param mPos Position of the upperLeft of the Quad
			* @param mSize Width and height of the Quad
			* @param mData Reference to a container with all the sensors for the area covered by the quad
			*
			*/
			QuadTree(const Coordinate& mPos, const int& mSize, const std::vector<Sensor*>& mData);

			/**
			* Constructor for QuadTree
			*
			* @param mData Reference to a container with all the sensors for the area covered by the quad
			*
			*/
			QuadTree(const std::vector<Sensor*>& mData);

			/// Destructor for QuadTree
			virtual ~QuadTree();

			//------------------------------------------------------------------ PRIVE
		protected:
			//----------------------------------------------------- Méthodes protégées
			void loadOriginTree(const Coordinate& mPos, const int& mSize, const std::vector<Sensor*>& mData);
			const std::vector<Sensor*>& searchPointWithoutCheck(const Coordinate& p, const double& area, const TREETYPE& quadrant,AreasScanned& areas)const;
			//----------------------------------------------------- Attributs protégés
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

