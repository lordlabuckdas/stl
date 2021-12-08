#include <stdexcept>
#include <string>
#include <vector>

namespace stl {
    template <typename T>
    class segment_tree {
        private:
        int* seg;
        int func;
        size_t size, cap;
        protected:
        void build(std::vector<T>&, size_t, size_t, size_t);
        void update(size_t, size_t, size_t, size_t&, T&);
        T query(size_t, size_t, size_t, size_t&, size_t&);
        public:
        segment_tree(std::vector<T> og, std::string type = "MIN");
        void update(size_t, T);
        T query(size_t, size_t);
    };

    template <typename T>
    segment_tree<T>::segment_tree(std::vector<T> og, std::string type) {
        switch(type) {
            case "MIN":
                this->func = 1;
                break;
            case "MAX":
                this->func = 2;
                break;
            case "GCD":
                this->func = 3;
                break;
            case "SUM":
                this->func = 4;
                break;
            default:
                throw std::invalid_argument("Function type not recognized");
        }
        this->size = og.size();
        this->cap = 4*og.size() + 1;
        this->seg = new int[this->cap];
        this->build(og, 1, 0, this->size - 1);
    }

    template <typename T>
    void segment_tree<T>::build(std::vector<T>& og, size_t node_id, size_t node_start, size_t node_end) {
        if(node_start == node_end) {
            this->seg[node_id] = og[node_start];
            return;
        }
        size_t mid = node_start + (node_end - node_start)/2;
        this->build(og, 2*node_id, node_start, mid);
        this->build(og, 2*node_id + 1, mid + 1, node_end);
        // TODO: switch(this->func)
        this->seg[node_id] = this->seg[2*node_id] + this->seg[2*node_id + 1];
    }

    template <typename T>
    void segment_tree<T>::update(size_t pos, T val) {
        this->update(1, 0, this->size() - 1, pos, val);
    }
    
    template <typename T>
    void segment_tree<T>::update(size_t node_id, size_t node_start, size_t node_end, size_t& pos, T& val) {
        if(node_start == node_end && node_start == pos) {
            this->seg[node_id] = val;
            return;
        }
        if(node_start > pos || node_end < pos) {
            return;
        }
        size_t mid = node_start + (node_end - node_start)/2;
        update(2*node_id, node_start, mid, pos, val);
        update(2*node_id + 1, mid + 1, node_end, pos, val);
        // TODO: switch(this->func)
        this->seg[node_id] = seg[2*node_id] + seg[2*node_id + 1];
    }

    template <typename T>
    T segment_tree<T>::query(size_t query_start, size_t query_end) {
        this->query(1, 0, this->size() - 1, query_start, query_end);
    }

    template <typename T>
    T segment_tree<T>::query(size_t node_id, size_t node_start, size_t node_end, size_t& query_start, size_t& query_end) {
        if(query_start <= node_start && node_end <= query_end) {
            return this->seg[node_id];
        }
        if(node_end < query_start || query_end < node_start) {
            return 0;
        }
        size_t mid = node_start + (node_end - node_start)/2;
        // TODO: switch(this->func)
        return query(2*node_id, node_start, mid, query_start, query_end) + query(2*node_id + 1, mid + 1, node_end, query_start, query_end);
    }
}
