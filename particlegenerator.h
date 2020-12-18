#ifndef PARTICLEGENERATOR_H
#define PARTICLEGENERATOR_H
#include <cstdlib>

class ParticleGenerator
{
public:
    ParticleGenerator();
    virtual ~ParticleGenerator();
    virtual void generate(float dt, size_t start_id, size_t end_id) = 0;
};

#endif // PARTICLEGENERATOR_H
