#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <algorithm>

#include "Vertex.h"

class GraphManager {
public:
    inline GraphManager() {};
    ~GraphManager();

    void createVertex(std::string vertex, std::vector<std::pair<std::string, int>> neighbors, float posX, float posY);
    void renderText(std::string label, sf::Vector2f pos, sf::Font& font, int size, sf::Color color, sf::RenderWindow& window);

    Vertex* getOneVertex(std::string vertexName);
    std::vector<Vertex* >* getVertices();
    int getMaxWeight(std::vector<Vertex*>& unexplored);
    void resetParentVertices();
    void resetMinDistancesFromSrc();
    void clearVertices();

private:
    std::vector<Vertex* > vertices;
};

