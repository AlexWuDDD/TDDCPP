#ifndef THREADPOOL_H
#define THREADPOOL_H

#include <string>
#include <deque>
#include <thread>
#include <memory>
#include <atomic>
#include <mutex>
#include <vector>
#include "Work.h"

class ThreadPool
{
public:
    virtual ~ThreadPool()
    {
        stop();
    }
    void stop()
    {
        done_ = true;
        for(auto& thread_item: threads_){
            thread_item.join();
        }
        // if(workThread_){
        //     workThread_->join();
        // }
    }

    void start(unsigned int numberOfThreads=1)
    {
        for(unsigned int i=0; i<numberOfThreads; ++i){
            threads_.emplace_back(std::thread(&ThreadPool::worker, this));
        }
        // workThread_ = std::make_shared<std::thread>(&ThreadPool::worker, this);
    }

    bool hasWork(){
        std::lock_guard<std::mutex> block(mutex_);
        return !workQueue_.empty();
    }

    virtual void add(Work work)
    {
        std::lock_guard<std::mutex> block(mutex_);
        workQueue_.push_front(work);
    }

    Work pullWork()
    {
        std::lock_guard<std::mutex> block(mutex_);
        if(workQueue_.empty()){return Work{};}
        auto work = workQueue_.back();
        workQueue_.pop_back();
        return work;
    }

private:
    void worker(){
        while(!done_){
            while(!done_ && !hasWork());
            if(done_)break;
            pullWork().execute();
        }
    }

    std::atomic<bool> done_{false};
    std::deque<Work> workQueue_;
    std::shared_ptr<std::thread> workThread_;
    std::mutex mutex_;
    std::vector<std::thread> threads_;
};

#endif