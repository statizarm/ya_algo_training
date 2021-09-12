SELECT DATE(s.date, 'start of month') AS monthDate,
       s.description AS description,
       s.name AS item_name,
       c.name AS category_name,
       b.name AS brand_name,
       SUM(s.shows) AS sum_shows,
       SUM(s.clicks) AS sum_clicks,
       SUM(s.orders) AS sum_orders,
       SUM(s.gmv) AS sum_gmv
FROM statistic s, categories c, brands b
WHERE s.category_id = c.id AND
      s.brand_id = b.id AND
      s.shows >= s.clicks AND
      s.clicks >= s.orders AND
      c.name NOT IN ('Варочные панели', 'Садовые измельчители') AND
      b.name NOT IN ('Apple', 'Samsung') AND
      s.date >= DATE('2021-04-01') AND
      s.date <= DATE('2021-07-31')
GROUP BY DATE(s.date, 'start of month'),
         s.description,
         s.name,
         c.name,
         b.name
ORDER BY monthDate ASC,
         sum_gmv DESC
LIMIT 100;
