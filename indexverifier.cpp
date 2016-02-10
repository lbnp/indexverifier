#include <vector>
#include <list>

int main()
{
    static const uint32_t CACHE_CAPACITY = 14;
    std::vector<uint32_t> indices;
    std::list<uint32_t> cache;
    uint32_t hits = 0;

    for (auto index: indices) {
        if ((auto iter = std::find(cache.begin(), cache.end(), index)) != cache.end()) {
            cache.erase(iter);
            cache.push_back(index);
            hits++;
        } else {
            // LRU
            if (cache.size() == CACHE_CAPACITY) {
                cache.pop_front();
                cache.push_back(index);
            }
        }
    }

    float ratio = hits / indices.size() * 100.0f;
    return 0;
}
