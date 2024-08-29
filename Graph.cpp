//Graph.cpp

#include "Graph.h"

#include <iostream>

int Graph::getIndex(std::string name)
{
    for (int i = 0; i < vertexCount; i++)
    {
        if (vertexesName[i] == name)
            return i;
    }
    return -1;
}

int Graph::getEdgeWeight(std::string v1, std::string v2)
{
    return matrix[getIndex(v1)][getIndex(v2)];
}

void Graph::addUser(std::string name)
{
    vertexesName[vertexCount++] = name;
}

void Graph::addEdge(std::string v1, std::string v2, int weight)
{
    matrix[getIndex(v1)][getIndex(v2)] = weight;
    matrix[getIndex(v2)][getIndex(v1)] = weight;
}

bool Graph::edgeExists(std::string v1, std::string v2)
{
    return matrix[getIndex(v1)][getIndex(v2)] > 0;
}

bool Graph::vertexExists(std::string name)
{
    for (int i = 0; i < vertexCount; i++)
        if (vertexesName[i] == name)
            return true;
    return false;
}

void Graph::showFriends(int handshake)
{
    std::cout << "Пары пользователей знакомых через три рукопожатия:" << std::endl;

    bool visited[SIZE];
    for (int i = 0; i < SIZE; i++)
        visited[i] = false;

    int path = 0;
    for (int i = 0; i < vertexCount - 1; i++)
    {
        findFriends(vertexesName[i], vertexesName[i], visited, handshake, path);
        visited[i] = true;
    }
}

void Graph::findFriends(std::string start, std::string current, bool visited[], int handshake, int path)
{
    if (path <= handshake && path > 0)
    {
        std::cout << start << " & " << current << std::endl;
    }

    if (path > handshake)
        return;

    visited[getIndex(current)] = true;
    for (int i = 0; i < vertexCount; i++)
    {
        if (edgeExists(current, vertexesName[i]) && !visited[i])
        {
            path += getEdgeWeight(current, vertexesName[i]);
            findFriends(start, vertexesName[i], visited, handshake, path);
        }
    }
    visited[getIndex(current)] = false;
}