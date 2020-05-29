#include "QuadTree.h"
#include <stdexcept>
#include <cmath>
#include <iostream>
namespace data {
	const std::vector<Sensor*>& QuadTree::searchPoint(const Coordinate& p, const int& area)const
	{
		if (!p.inSquare(position, quadSize)) {
			std::cout << "Point " << p.toString() << " not in main origin Quad " << position.toString() + " " + std::to_string(quadSize) << std::endl;
			return data;
		}
		else {
			return searchPointWithoutCheck(p, area);
		}

		
		
	}
	const std::vector<Sensor*>& QuadTree::searchPointWithoutCheck(const Coordinate& p, const int& area)const
	{

		if (area > quadSize/2 && area < quadSize) {
			std::cout <<"Found point " << p.toString() <<" in " << position.toString() + " " + std::to_string(quadSize) << std::endl;
			return data;
		}
		else {
			if (p.inSquare(upperLeft->position, upperLeft->quadSize)) {
				return upperLeft->searchPoint(p, area);
			}
			else if (p.inSquare(upperRight->position, upperRight->quadSize)) {
				return upperRight->searchPoint(p, area);
			}
			else if (p.inSquare(lowerLeft->position, lowerLeft->quadSize))
			{
				return lowerLeft->searchPoint(p, area);
			}
			else if (p.inSquare(lowerRight->position, lowerRight->quadSize))
			{
				return lowerRight->searchPoint(p, area);
			}
			else {
				throw std::invalid_argument("Position in Quad tree error");
			}
		}

	}
	data::QuadTree::QuadTree(const QuadTree* myParent, const TREETYPE& tType)
	{
		parent = myParent;
		type = tType;
		quadSize = myParent->quadSize / 2;


		switch (type)
		{
		case data::TREETYPE::UPPERRIGHT:
			position = Coordinate(myParent->position.getLongitude()+quadSize,myParent->position.getLatitude());
			break;
		case data::TREETYPE::UPPERLEFT:
			position = Coordinate(myParent->position.getLongitude(), myParent->position.getLatitude());
			break;
		case data::TREETYPE::LOWERRIGHT:
			position = Coordinate(myParent->position.getLongitude() + quadSize, myParent->position.getLatitude()+quadSize);
			break;
		case data::TREETYPE::LOWERLEFT:
			position = Coordinate(myParent->position.getLongitude(), myParent->position.getLatitude()+quadSize);
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
		loadOriginTree(mPos, mSize, mData);
	}

	QuadTree::QuadTree(const std::vector<Sensor*>& mData)
	{
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
		int size = std::max(diff.getLatitude(), diff.getLongitude()) +10;
		int multiple = log2(size) +1;
		size = pow(2, multiple);
		loadOriginTree(minVal - 5, size, mData);
	}

	QuadTree::~QuadTree()
	{
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