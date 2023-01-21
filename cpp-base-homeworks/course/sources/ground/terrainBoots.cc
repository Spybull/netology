#include "terrainBoots.h"

TerrainBoots::TerrainBoots(double s, double mt, std::string n) : Ground(s, mt, n) {}
TerrainBoots::TerrainBoots(double s, double mt) : Ground(s, mt, "TerrainBoots") {}

void TerrainBoots::calcTime(double d) {
    Ground::calcTime(d);
    --stopCount;
    fullTime += 10 + stopCount * 5;
}