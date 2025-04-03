//
// Created by couland-q on 29/03/2022.
//

#ifndef PROJECTISO_MAP_H
#define PROJECTISO_MAP_H

#include <iostream>
#include <string>
#include <vector>


#include "types.h"
#include "tools.h"


struct Tile {
    std::string texture_name;
    mVec3<int> pos; // x, y, z
    int size;

    Tile() : pos(mVec3<int>{0, 0, 0}), size(-1) {}

    explicit Tile(std::string name): texture_name(std::move(name)), pos(mVec3<int>{0, 0, 0}), size(-1) {}

    Tile(std::string name, int size, int x, int y, int z=0):
        texture_name(std::move(name)), pos(mVec3<int>{x, y, z}), size(size) {}

    /*Vector2 get_pos() const {
        return Vector2{static_cast<float>(pos.x), static_cast<float>(pos.y)};
    }*/

    mVec2<int> getPosAsMvec2() const {
        return mVec2<int>{pos.x, pos.y};
    }

    mVec2<int> getScreenPosAsMvec2() const {
        return mVec2<int>{pos.x * size, pos.y * size};
    }

    /*Vector2 get_pos_size(Texture2D texture) const {
        return Vector2{static_cast<float>(pos.x * texture.width), static_cast<float>(pos.y * texture.height)};
    }*/
};

class Map {
public:
    Map();
    ~Map();

    mVec2<uint>& getSize();
    std::vector<Tile>& getTiles();

    Tile& getTileAt(uint x, uint y);

    void rotateClockwise();
    void rotateCounterClockwise();
    void reorderTileByCoordinates();

    void makeTestMap();
    void generateCuteMap();
    bool adjacentZDiffIsBiggerThan(Tile& tile, int max_level);

private:
    mVec2<uint> size;
    std::vector<Tile> tiles;
};

#endif //PROJECTISO_MAP_H
