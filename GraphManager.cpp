#include "include/GraphManager.h"

int GraphManager::getMaxWeight(std::vector<Vertex*>& unexplored) {
    int maxWeight = 0;

    for (size_t i = 0; i < unexplored.size(); i++) {
        Vertex* currrentVertex = unexplored.at(i);

        for (size_t k = 0; k < currrentVertex->neighbors.size(); k++) {
            std::pair<std::string, int>& currentPair = currrentVertex->neighbors.at(k);

            if (currentPair.second > maxWeight)
                maxWeight = currentPair.second;
        }
    }

    return maxWeight;
}

void GraphManager::createVertex(
    std::string vertex,
    std::vector<std::pair<std::string, int>> neighbors,
    float posX,
    float posY
) {
    const int vertexWidth = 20;
    const int vertexHeight = 20;
    Vertex* createdVertex = new Vertex(vertex, neighbors);

    createdVertex->setPosition(sf::Vector2f(posX, posY));
    createdVertex->setDimensions(sf::Vector2f(vertexWidth, vertexHeight));

    this->vertices.push_back(createdVertex);
}

void GraphManager::renderText(
    std::string label,
    sf::Vector2f pos,
    sf::Font& font, int size,
    sf::Color color,
    sf::RenderWindow& window
) {
    sf::Text rectText;
    rectText.setPosition(pos);
    rectText.setFont(font);
    rectText.setString(label);
    rectText.setCharacterSize(size);
    rectText.setFillColor(color);

    window.draw(rectText);
}

Vertex* GraphManager::getOneVertex(std::string vertexName) {
    auto foundVertex = std::find_if(this->vertices.begin(), this->vertices.end(), [vertexName](const Vertex* currentVertex) {
        return currentVertex->vertexName == vertexName;
        });

    if (foundVertex != this->vertices.end())
        return *foundVertex;
    else
        return NULL;
}

std::vector<Vertex* >* GraphManager::getVertices() {
    return &this->vertices;
}

void GraphManager::resetParentVertices() {
    for (size_t i = 0; i < this->vertices.size(); i++) {
        this->vertices.at(i)->parent = nullptr;
    }
}

void GraphManager::resetMinDistancesFromSrc() {
    for (size_t i = 0; i < this->vertices.size(); i++) {
        this->vertices.at(i)->minDistanceFromSrc = INF;
    }
}

void GraphManager::clearVertices() {
    for (int i = 0; i < this->vertices.size(); i++) {
        delete this->vertices.at(i);
    }

    this->vertices.clear();
}

GraphManager::~GraphManager() {
    for (int i = 0; i < this->vertices.size(); i++) {
        delete this->vertices.at(i);
    }

    this->vertices.clear();
}

