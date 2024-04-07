#pragma once
#include <string>

// Land color (subclass of tile)
enum Color
{
    eNoColor = -1,
    eGreen = 1,
    eBlue,
    ePurple,
    eLightBlue,
    eLightPurple,
    eOrange,
    eRed,
    eYellow,
};

enum TileType
{
    eNoType = -1,

    // NonBuyableTile: 1 < value < 10
    eLand = 1,
    ePublicservice,
    eTrainStation,

    // BuyableTile : value > 10
    eCommunity = 11,
    eFreeParking,
    eGoToPrison,
    eHazard,
    eLuxuryTax,
    ePrison,
    eStart,
    eTax,
};

// Player
const int kDefaultMoneyAmount = 500;

// Board
const int kDefaultGameHotels = 12;
const int kDefaultGameHouses = 36;

// Tiles' names
const std::string tileName[41] = {"Départ", "Bd de Belleville", "Caisse de Communauté", "Rue Lecourbe", "Impôt sur le revenu", "Gare Montparnasse", "Rue de Vaugirard", "Chance", "Rue de Courcelles", "Avenue de la République", "Simple visite", "Bd de la Villette", "Compagnie d'électricité", "Avenue de Neuilly", "Rue de Paradis", "Gare de Lyon", "Avenue Mozart", "Caisse de Communauté", "Bd Saint-Michel", "Place Pigalle", "Parc gratuit", "Avenue Matignon", "Chance", "Bd Malesherbes", "Avenue Henri-Martin", "Gare du Nord", "Faubourg Saint-Honoré", "Place de la Bourse", "Compagnie des eaux", "Rue La Fayette", "Allez en prison", "Avenue de Breteuil", "Avenue Foch", "Caisse de Communauté", "Bd des Capucines", "Gare Saint-Lazare", "Chance", "Champs-Élysées", "Taxe de luxe", "Rue de la Paix", "Prison"};