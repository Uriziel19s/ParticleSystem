#include "particleupdaters.h"

void LawOfUniversalGravitationUpdater::Update(double dt, ParticleDataContainer *p, MultithreadOverseer *task_menager)
{
    size_t range_per_task = p->count_alive_ / task_menager->number_of_workers_;
    size_t begin_index = 0;
    for(size_t i = 0; i < task_menager->number_of_workers_ - 1; i++)
    {
        task_menager->AddTask(std::async(std::launch::deferred, &LawOfUniversalGravitationUpdater::Calculate, this, static_cast<float>(dt), p, begin_index, begin_index + range_per_task));
        begin_index += range_per_task;
    }
    task_menager->AddTask(std::async(std::launch::deferred, &LawOfUniversalGravitationUpdater::Calculate, this, static_cast<float>(dt), p, begin_index, p->count_alive_));

}

void LawOfUniversalGravitationUpdater::Calculate(float dt, ParticleDataContainer *p, size_t start_id, size_t end_id)
{
    glm::vec3 particleCenterVector;
    for(size_t i = start_id; i < end_id; i++)
    {
        particleCenterVector =    center_position_ - p->positions_[i];
        if(glm::length(particleCenterVector))
        {
            p->velocity_[i] += center_mass_ * particleCenterVector / glm::pow(glm::length(particleCenterVector), 3.0f) * dt ;
        }
        p->positions_[i] += p->velocity_[i] * dt;

    }
}

void NBodyUpdater::Update(double dt, ParticleDataContainer *p, MultithreadOverseer *task_menager)
{

    size_t range_per_task = p->count_alive_ / task_menager->number_of_workers_;
    size_t begin_index = 0;
    for(size_t i = 0; i < task_menager->number_of_workers_ - 1; i++)
    {
        task_menager->AddTask(std::async(std::launch::deferred, &NBodyUpdater::Calculate, this, static_cast<float>(dt), p, begin_index, begin_index + range_per_task));
        begin_index += range_per_task;
    }
    task_menager->AddTask(std::async(std::launch::deferred, &NBodyUpdater::Calculate, this, static_cast<float>(dt), p, begin_index, p->count_alive_));
    task_menager->WaitForAllTasks();


    for(size_t j = 0; j < p->count_alive_; j++)
    {
        p->positions_[j] += p->velocity_[j] * static_cast<float>(dt);
    }

}

void NBodyUpdater::Calculate(float dt, ParticleDataContainer *p, size_t start_id, size_t end_id)
{
    glm::vec3 particleCenterVector;
    for(size_t i = start_id; i < end_id; i++)
    {
        for(size_t j = 0; j < p->count_alive_; j++)
        {
            if(i != j)
            {
                particleCenterVector = p->positions_[j] - p->positions_[i];
                p->velocity_[i] += p->mass_[j] * particleCenterVector / glm::pow(glm::length(particleCenterVector), 3.0f) * dt ;
            }
        }

    }

}
