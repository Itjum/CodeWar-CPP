#include "dnl.hh"

size_t min_elt_length(const std::vector<std::string>& req)
{
    auto res = std::min_element(
        req.begin(), req.end(),
        [](const auto& a, const auto& b) { return a.size() < b.size(); });
    return res->size();
}

size_t max_elt_length(const std::vector<std::string>& req)
{
    auto res = std::max_element(
        req.begin(), req.end(),
        [](const auto& a, const auto& b) { return a.size() < b.size(); });
    return res->size();
}

size_t sum_elt_length(const std::vector<std::string>& req)
{
    auto res = std::accumulate(req.begin(), req.end(), std::string(""));
    return res.length();
}

size_t count_elt(const std::vector<std::string>& req, const std::string& elt)
{
    auto res = std::count(req.begin(), req.end(), elt);
    return res;
}

size_t count_duplicate(const std::vector<std::string>& req)
{
    std::vector<std::string> temp = req;
    std::sort(temp.begin(), temp.end());
    auto unique_arr = std::unique(temp.begin(), temp.end());
    temp.erase(unique_arr, temp.end());
    return req.size() - temp.size();
}