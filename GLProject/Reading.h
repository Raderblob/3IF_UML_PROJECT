#pragma once
#include <string>
namespace data {
	enum class READINGTYPE
	{
		O3,NO2,SO2,PM10
	};

	class Reading
	{
		//----------------------------------------------------------------- PUBLIC
	public:
		//----------------------------------------------------- Méthodes publiques

		/**
		* Returns type of reading as string
		*
		* 
		* @return String containing type of Reading
		*/
		std::string getType()const;

		/**
		* Returns Value as double
		*
		*
		* @return reference to value
		*/
		const double& getValue()const;

		/// Returns reference to type as enum
		const READINGTYPE& getEType()const;

		//------------------------------------------------- Surcharge d'opérateurs

		//-------------------------------------------- Constructeurs - destructeur

		/**
		* Constructor for Reading
		*
		* @param type type of Reading as String (Needs to be one of the 4 types)
		* @see READINGTYPE
		* @param val Value of reading
		*/
		Reading(const std::string& type, const double& val);

		//------------------------------------------------------------------ PRIVE
	protected:
		//----------------------------------------------------- Méthodes protégées
		READINGTYPE type;
		double value;
		//----------------------------------------------------- Attributs protégés
	};
}

