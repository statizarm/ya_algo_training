import json
import sys


def calc_count(c, rc):
    res = c - rc
    res = 0 if res < 0 else res
    return res


events = json.load(sys.stdin)

orders = dict()
max_event = dict()

for e in events:
    event_id = e['event_id']
    order_id = e['order_id']
    item_id = e['item_id']
    count = e['count']
    return_count = e['return_count']
    status = e['status']
    order = orders.get(order_id)
    if order is None:
        orders[order_id] = {item_id: {'count': calc_count(count, return_count), 'status': status}}
        max_event[(order_id, item_id)] = event_id
    elif event_id > max_event.get((order_id, item_id), 0):
        order[item_id] = {'count': calc_count(count, return_count), 'status': status}
        max_event[(order_id, item_id)] = event_id

res = []

for order_id, order in orders.items():
    items = []

    for item_id, item in order.items():
        count = item['count']
        if count != 0 and item['status'] != 'CANCEL':
            items.append({'id': item_id, 'count': count})

    if len(items) != 0:
        res.append({'id': order_id, 'items': items})

json.dump(res, sys.stdout)
print('')
