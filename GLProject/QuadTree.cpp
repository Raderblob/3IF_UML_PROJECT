#include "QuadTree.h"
#include <stdexcept>
#include <cmath>
#include <iostream>
namespace data {
	namespace tree {
		std::vector<Sensor*> QuadTree::searchPoint(const Coordinate& p, const double& area)const
		{
			Coordinate upperLeftCoord = p - double(area)/2.0;
			Coordinate lowerRightCoord = p + double(area) /2.0;
			Coordinate upperRightCoord = p + Coordinate(double(area) /2.0,-double(area) /2.0);
			Coordinate lowerLeftCoord = p + Coordinate(-double(area) /2.0 , double(area) /2.0);

			bool upperLeftIn = upperLeftCoord.inSquare(position, quadSize);
			bool lowerRightIn = lowerRightCoord.inSquare(position, quadSize);
			bool upperRightIn = upperRightCoord.inSquare(position, quadSize);
			bool lowerLeftIn = lowerLeftCoord.inSquare(position, quadSize);
			if (!upperLeftIn || !lowerRightIn || !upperRightIn || !lowerLeftIn) {

				std::vector<Sensor*> res = data;
				if (lowerLeftIn || lowerRightIn || upperRightIn || upperLeftIn) {
					//
					res.clear();
					AreasScanned areas;
					if (upperLeftIn && !areas.upperLeft) {
						res = searchPointWithoutCheck(upperLeftCoord, area, TREETYPE::UPPERLEFT,areas);
					}
					if (lowerRightIn && !areas.lowerRight) {
						auto tmp = searchPointWithoutCheck(lowerRightCoord, area, TREETYPE::LOWERRIGHT, areas);
						res.insert(res.end(), tmp.begin(), tmp.end());
					}
					if (upperRightIn && !areas.upperRight) {
						auto tmp = searchPointWithoutCheck(upperRightCoord, area, TREETYPE::UPPERRIGHT, areas);
						res.insert(res.end(), tmp.begin(), tmp.end());
					}
					if (lowerLeftIn && !areas.lowerLeft) {
						auto tmp = searchPointWithoutCheck(lowerLeftCoord, area, TREETYPE::LOWERLEFT, areas);
						res.insert(res.end(), tmp.begin(), tmp.end());
					}
				}
				else {
					std::cout << "No Points in Origin Quad" << std::endl;
				}
				for (int i = 0; i < res.size(); ++i) {
					if (!res.at(i)->getPosition().inSquare(upperLeftCoord, area)) {
						res.erase(res.begin() + i);
						i--;
					}
				}
#ifdef DEBUG
				std::cout << "Not in main origin Quad " << position.toString() + " " + std::to_string(quadSize) << std::endl;
				std::cout << "Number found " << res.size() << std::endl;
#endif // DEBUG

				return res;
			}
			else {

				AreasScanned areas;
				std::vector<Sensor*> res;
				int cnt = 1;

				res = searchPointWithoutCheck(upperLeftCoord, area, TREETYPE::UPPERLEFT, areas);
				
				if (!areas.lowerRight) {
					auto tmp = searchPointWithoutCheck(lowerRightCoord, area, TREETYPE::LOWERRIGHT, areas);
					res.insert(res.end(), tmp.begin(), tmp.end());
					cnt++;
				}
				if (!areas.upperRight) {
					auto tmp = searchPointWithoutCheck(upperRightCoord, area, TREETYPE::UPPERRIGHT, areas);
					res.insert(res.end(), tmp.begin(), tmp.end());
					cnt++;
				}
				if (!areas.lowerLeft) {
					auto tmp = searchPointWithoutCheck(lowerLeftCoord, area, TREETYPE::LOWERLEFT, areas);
					res.insert(res.end(), tmp.begin(), tmp.end());
					cnt++;
				}

				for (int i = 0; i < res.size(); ++i) {
					if (!res.at(i)->getPosition().inSquare(upperLeftCoord, area)) {
						res.erase(res.begin() + i);
						i--;
					}
				}
#ifdef DEBUG
				//std::cout << "Found Data for " << p.toString()<<" sensors size:" << res.size() << std::endl;
				//std::cout << cnt << std::endl;
#endif // DEBUG



				return res;
			}



		}
		const Coordinate& QuadTree::getUpperLeft() const
		{
			return position;
		}
		Coordinate QuadTree::getLowerLeft() const
		{
			return position + Coordinate(0, quadSize);
		}
		Coordinate QuadTree::getUpperRight() const
		{
			return position + Coordinate(quadSize, 0);
		}
		Coordinate QuadTree::getLowerRight() const
		{
			return position + quadSize;
		}
		const std::vector<Sensor*>& QuadTree::searchPointWithoutCheck(const Coordinate& p, const double& area, const TREETYPE& quadrant,AreasScanned& areas)const
		{

			if (area > quadSize / 2 && area <= quadSize) {
#ifdef DEBUG
				std::cout << "Found point " << p.toString() << " in " << position.toString() + " " + std::to_string(quadSize) << std::endl;
#endif // DEBUG

				Coordinate lowerRightCoord, lowerLeftCoord, upperRightCoord, upperLeftCoord;
				switch (quadrant)
				{
				case TREETYPE::UPPERLEFT:
					lowerRightCoord = p + area;
					upperRightCoord = p + Coordinate(area, 0);
					lowerLeftCoord = p + Coordinate(0, area);
					areas.upperLeft = true;
					break;
				case TREETYPE::UPPERRIGHT:
					upperLeftCoord = p - Coordinate(area,0);
					lowerRightCoord = p + Coordinate(0,area);
					lowerLeftCoord = p + Coordinate(-area,area);
					areas.upperRight = true;
					break;
				case TREETYPE::LOWERLEFT:
					upperLeftCoord = p - Coordinate(0, area);
					upperRightCoord = p + Coordinate(area,-area);
					lowerRightCoord = p + Coordinate(area,0);
					areas.lowerLeft = true;
					break;
				case TREETYPE::LOWERRIGHT:
					upperLeftCoord = p - area;
					upperRightCoord = p - Coordinate(0, area);
					lowerLeftCoord = p - Coordinate(area, 0);
					areas.lowerRight = true;
					break;
				default:
					throw std::invalid_argument("type wrong");
					break;
				}
				if (!areas.upperLeft && upperLeftCoord.inSquare(position, quadSize)) {
					areas.upperLeft = true;
				}
				if (!areas.lowerLeft && lowerLeftCoord.inSquare(position, quadSize)) {
					areas.lowerLeft = true;
				}
				if (!areas.upperRight && upperRightCoord.inSquare(position, quadSize)) {
					areas.upperRight = true;
				}
				if (!areas.lowerRight && lowerRightCoord.inSquare(position, quadSize)) {
					areas.lowerRight = true;
				}
				return data;
			}
			else {
				if (p.inSquare(upperLeft->position, upperLeft->quadSize)) {
					return upperLeft->searchPointWithoutCheck(p, area, quadrant,areas);
				}
				else if (p.inSquare(upperRight->position, upperRight->quadSize)) {
					return upperRight->searchPointWithoutCheck(p, area, quadrant, areas);
				}
				else if (p.inSquare(lowerLeft->position, lowerLeft->quadSize))
				{
					return lowerLeft->searchPointWithoutCheck(p, area, quadrant, areas);
				}
				else if (p.inSquare(lowerRight->position, lowerRight->quadSize))
				{
					return lowerRight->searchPointWithoutCheck(p, area, quadrant, areas);
				}
				else {
					throw std::invalid_argument("Position in Quad tree error");
				}
			}

		}
		QuadTree::QuadTree(const QuadTree* myParent, const TREETYPE& tType)
		{
#ifdef DEBUG
			std::cout << "Constructor for QuadTree" << std::endl;
#endif // DEBUG

			parent = myParent;
			type = tType;
			quadSize = myParent->quadSize / 2;


			switch (type)
			{
			case TREETYPE::UPPERRIGHT:
				position = Coordinate(myParent->position.getLongitude() + quadSize, myParent->position.getLatitude());
				break;
			case TREETYPE::UPPERLEFT:
				position = Coordinate(myParent->position.getLongitude(), myParent->position.getLatitude());
				break;
			case TREETYPE::LOWERRIGHT:
				position = Coordinate(myParent->position.getLongitude() + quadSize, myParent->position.getLatitude() + quadSize);
				break;
			case TREETYPE::LOWERLEFT:
				position = Coordinate(myParent->position.getLongitude(), myParent->position.getLatitude() + quadSize);
				break;
			default:
				throw std::invalid_argument("Invalid type");
			}



			for (auto sensor : parent->data) {
				if (sensor->getPosition().inSquare(position, quadSize)) {
					data.push_back(sensor);
				}
			}

			if (quadSize > 1) {
				upperLeft = new QuadTree(this, TREETYPE::UPPERLEFT);
				lowerLeft = new QuadTree(this, TREETYPE::LOWERLEFT);
				upperRight = new QuadTree(this, TREETYPE::UPPERRIGHT);
				lowerRight = new QuadTree(this, TREETYPE::LOWERRIGHT);
			}
			else {
				upperLeft = nullptr;
				lowerLeft = nullptr;
				upperRight = nullptr;
				lowerRight = nullptr;
			}
		}

		QuadTree::QuadTree(const Coordinate& mPos, const int& mSize, const std::vector<Sensor*>& mData)
		{
#ifdef DEBUG
			std::cout << "Constructor for QuadTree" << std::endl;
#endif // DEBUG
			loadOriginTree(mPos, mSize, mData);
		}

		QuadTree::QuadTree(const std::vector<Sensor*>& mData)
		{
#ifdef DEBUG
			std::cout << "Constructor for QuadTree" << std::endl;
#endif // DEBUG
			Coordinate minVal = mData.at(0)->getPosition();
			Coordinate maxVal = mData.at(0)->getPosition();
			for (auto sensor : mData) {
				if (minVal.getLongitude() > sensor->getPosition().getLongitude()) {
					minVal.setLongitude(sensor->getPosition().getLongitude());
				}
				if (minVal.getLatitude() > sensor->getPosition().getLatitude()) {
					minVal.setLatitude(sensor->getPosition().getLatitude());
				}

				if (maxVal.getLongitude() < sensor->getPosition().getLongitude()) {
					maxVal.setLongitude(sensor->getPosition().getLongitude());
				}
				if (maxVal.getLatitude() < sensor->getPosition().getLatitude()) {
					maxVal.setLatitude(sensor->getPosition().getLatitude());
				}
			}

			Coordinate diff = maxVal - minVal;
			int size = (int)((diff.getLatitude() > diff.getLongitude() ? diff.getLatitude() : diff.getLatitude())) + 10;
			int multiple = (int)log2(size) + 1;
			size = (int)pow(2, multiple);
			loadOriginTree(minVal - 5, size, mData);
		}

		QuadTree::~QuadTree()
		{
#ifdef DEBUG
			std::cout << "Destructor for QuadTree" << std::endl;
#endif // DEBUG
			delete upperLeft;
			delete lowerLeft;
			delete upperRight;
			delete lowerRight;
		}

		void QuadTree::loadOriginTree(const Coordinate& mPos, const int& mSize, const std::vector<Sensor*>& mData)
		{
			data = mData;
			parent = nullptr;
			type = TREETYPE::ORIGIN;
			quadSize = mSize;
			position = mPos;
			if (quadSize > 1) {
				upperLeft = new QuadTree(this, TREETYPE::UPPERLEFT);
				lowerLeft = new QuadTree(this, TREETYPE::LOWERLEFT);
				upperRight = new QuadTree(this, TREETYPE::UPPERRIGHT);
				lowerRight = new QuadTree(this, TREETYPE::LOWERRIGHT);
			}
			else {
				upperLeft = nullptr;
				lowerLeft = nullptr;
				upperRight = nullptr;
				lowerRight = nullptr;
			}
		}

	}

}