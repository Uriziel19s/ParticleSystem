﻿#ifndef PARTICLEGENERATORS_H
#define PARTICLEGENERATORS_H
#include <random>

#include <glm/gtx/rotate_vector.hpp>
#include "particlegenerator.h"


class SpherePositionGenerator : public ParticleGenerator
{
public:
    float radius_{1};
    glm::vec3 center_{0.0f, 0.0f, 0.0f};

    SpherePositionGenerator() { }
    ~SpherePositionGenerator() override{ }
    void generate(double dt, ParticleDataContainer *p, MultithreadOverseer *task_menager, size_t start_id, size_t end_id) override;
};

class CirclePositionGenerator : public ParticleGenerator
{
public:
    float radius_{1.0f};
    float minimal_radius{0.0f};
    glm::vec3 center_{0.0f, 0.0f, 0.0f};
    CirclePositionGenerator() { }
    ~CirclePositionGenerator() override { }
    void generate(double dt, ParticleDataContainer *p, MultithreadOverseer *task_menager, size_t start_id, size_t end_id) override;


};

class OneColorGenerator : public ParticleGenerator
{
public:
    glm::vec3 color_{1.0f, 1.0f, 1.0f};

    OneColorGenerator() { }
    ~OneColorGenerator() override { }
    void generate(double dt, ParticleDataContainer *p, MultithreadOverseer *task_menager, size_t start_id, size_t end_id) override;
};

class BasicVelocityGenerator : public ParticleGenerator
{
public:
    glm::vec3 velocity_ = {0.0f, 0.0f, 0.0f};

    BasicVelocityGenerator() { }
    ~BasicVelocityGenerator() {}

    void generate(double dt, ParticleDataContainer *p, MultithreadOverseer *task_menager, size_t start_id, size_t end_id) override;

};

class BasicAccelerationGenerator : public ParticleGenerator
{
public:
    glm::vec3 acceleration_ = {0.0f, 0.0f, 0.0f};
    BasicAccelerationGenerator() { }
    ~BasicAccelerationGenerator() override { }

    void generate(double dt, ParticleDataContainer *p, MultithreadOverseer *task_menager, size_t start_id, size_t end_id) override;
};

class BasicMassGenerator : public ParticleGenerator
{
public:
    float mass_ = 0.0f;
    BasicMassGenerator() { }
    ~BasicMassGenerator() override { }

    void generate(double dt, ParticleDataContainer *p, MultithreadOverseer *task_menager, size_t start_id, size_t end_id) override;
};

class RandomMassGenerator : public ParticleGenerator
{
public:
    float min_mass_{0.0f};
    float max_mass = {1.0f};
    RandomMassGenerator() { }
    ~RandomMassGenerator() override { }

    void generate(double dt, ParticleDataContainer *p, MultithreadOverseer *task_menager, size_t start_id, size_t end_id) override;
};
  #endif // PARTICLEGENERATORS_H
