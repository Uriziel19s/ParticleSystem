#include "particlegenerators.h"



void BasicVelocityGenerator::generate(double dt, ParticleDataContainer *p, MultithreadOverseer *task_menager, size_t start_id, size_t end_id)
{
    for(size_t i = start_id; i < end_id; i++)
    {
        p->velocity_[i] = velocity_;
    }
}

void BasicAccelerationGenerator::generate(double dt, ParticleDataContainer *p, MultithreadOverseer *task_menager, size_t start_id, size_t end_id)
{
    for(size_t i = start_id; i < end_id; i++)
    {
        p->acceleration_[i] = acceleration_;
    }
}

void BasicMassGenerator::generate(double dt, ParticleDataContainer *p, MultithreadOverseer *task_menager, size_t start_id, size_t end_id)
{
    for(size_t i = start_id; i < end_id; i++)
    {
        p->mass_[i] = mass_;
    }
}

void CirclePositionGenerator::generate(double dt, ParticleDataContainer *p, MultithreadOverseer *task_menager, size_t start_id, size_t end_id)
{
    std::minstd_rand gen(std::random_device{}());
    std::uniform_real_distribution<float> dist_angle(0, 2.0f * M_PIf32);
    std::uniform_real_distribution<float> dist_radius(minimal_radius, radius_);
    float angle = 0;
    for(size_t i = start_id; i < end_id; i++)
    {
        angle = dist_angle(gen);
        p->positions_[i] = center_ + glm::vec3(dist_radius(gen) * glm::cos(angle), radius_ * glm::sin(angle), 0.0f);

    }
}

void OneColorGenerator::generate(double dt, ParticleDataContainer *p, MultithreadOverseer *task_menager, size_t start_id, size_t end_id)
{
    for(size_t i = start_id; i < end_id; i++)
    {
        p->color_[i] = color_;
    }
}

void SpherePositionGenerator::generate(double dt, ParticleDataContainer *p, MultithreadOverseer *task_menager, size_t start_id, size_t end_id)
{
    std::minstd_rand gen(std::random_device{}());
    std::uniform_real_distribution<float> dist(0.0f, 1.0f);
    for(size_t i = start_id; i < end_id; i++)
    {
        float z = -1.0f + 2.0f * dist(gen);       // uniformly distributed z
        float longitude = 2.0f * M_PIf32 * dist(gen); // uniformly distributed longitude

        float rh = sqrtf(1.0f - z * z);    // horizontal radius (= r sin(colatitude), with r=1 )
        float x = rh * cosf(longitude);
        float y = rh * sinf(longitude);
        p->positions_[i] = std::move(center_ + glm::vec3(radius_ * x, radius_ * y, radius_ * z));
    }
}






void RandomMassGenerator::generate(double dt, ParticleDataContainer *p, MultithreadOverseer *task_menager, size_t start_id, size_t end_id)
{
    std::minstd_rand gen(std::random_device{}());
    std::uniform_real_distribution<float> dist(min_mass_, max_mass);
    for(size_t i = start_id; i < end_id; i++)
    {
        p->mass_[i] = dist(gen);
    }
}
