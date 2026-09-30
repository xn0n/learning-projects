using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace deixtra.Classes
{
    class PriorityQueue<T>
    {
        private SortedDictionary<int, Queue<T>> _dictionary = new SortedDictionary<int, Queue<T>>();

        public void Enqueue(int priority, T item)
        {
            if (!_dictionary.ContainsKey(priority))
            {
                _dictionary.Add(priority, new Queue<T>());
            }
            _dictionary[priority].Enqueue(item);
        }

        public T Dequeue()
        {
            if (_dictionary.Count == 0)
            {
                throw new InvalidOperationException("The priority queue is empty");
            }

            var firstKey = _dictionary.Keys.Min();
            var queue = _dictionary[firstKey];
            var item = queue.Dequeue();

            if (queue.Count == 0)
            {
                _dictionary.Remove(firstKey);
            }

            return item;
        }

        public int Count
        {
            get
            {
                int count = 0;
                foreach (var queue in _dictionary.Values)
                {
                    count += queue.Count;
                }
                return count;
            }
        }
    }
}
