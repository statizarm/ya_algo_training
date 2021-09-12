import sys
import collections
import re

MarketRow = collections.namedtuple('MarketRow', ['shop_id', 'shop_name'])
BillingRow = collections.namedtuple('BillingRow', ['order_id', 'shop_id', 'cost'])
ResultRow = collections.namedtuple('ResultRow', ['order_id', 'shop_name', 'shop_id', 'cost'])

MarketScheme = collections.namedtuple('BillingScheme', ['shop_id_id', 'shop_name_id'])
BillingScheme = collections.namedtuple('BillingScheme', ['order_id_id', 'shop_id_id', 'cost_id'])


def print_res(res: ResultRow):
    print(f'{res.order_id},{res.shop_name},{res.shop_id},{res.cost}')


def parse_billing_row(s: str, scheme: BillingScheme) -> BillingRow:
    t = re.split(',| |\n', s)
    return BillingRow(int(t[scheme.order_id_id]), int(t[scheme.shop_id_id]), int(t[scheme.cost_id]))


def parse_market_row(s: str, scheme: MarketScheme) -> MarketRow:
    t = re.split(',| |\n', s)
    return MarketRow(int(t[scheme.shop_id_id]), t[scheme.shop_name_id])


def parse_billing_scheme(s: str) -> BillingScheme:
    t = re.split(',| |\n', s)
    return BillingScheme(t.index('order_id'), t.index('shop_id'), t.index('cost'))


def parse_market_scheme(s: str) -> MarketScheme:
    t = re.split(',| |\n', s)
    return MarketScheme(t.index('shop_id'), t.index('shop_name'))


def join(m: MarketRow, b: BillingRow) -> ResultRow:
    return ResultRow(b.order_id, m.shop_name, m.shop_id, b.cost)


def main():
    market_filename, billing_filename = sys.stdin.readline().split()

    market_file = open(market_filename)
    billing_file = open(billing_filename)

    market_scheme = parse_market_scheme(market_file.readline())
    billing_scheme = parse_billing_scheme(billing_file.readline())

    sys.stdout.write('order_id,shop_name,shop_id,cost\n')

    try:
        m = market_file.readline().split(',')
        m_shop_id = int(m[market_scheme.shop_id_id])
        b = billing_file.readline().split(',')
        b_shop_id = int(b[billing_scheme.shop_id_id])
    except:
        return

    try:
        while True:
            if b_shop_id > m_shop_id:
                m = market_file.readline().split(',')
                m_shop_id = int(m[market_scheme.shop_id_id])
            else:
                while b_shop_id < m_shop_id:
                    b = billing_file.readline().split(',')
                    b_shop_id = int(b[billing_scheme.shop_id_id])

                while b_shop_id == m_shop_id:
                    sys.stdout.write(','.join([b[billing_scheme.order_id_id].strip(),
                                               m[market_scheme.shop_name_id].strip(),
                                               m[market_scheme.shop_id_id].strip(),
                                               b[billing_scheme.cost_id]]))
                    b = billing_file.readline().split(',')
                    b_shop_id = int(b[billing_scheme.shop_id_id])
    except:
        pass


if __name__ == '__main__':
    main()
