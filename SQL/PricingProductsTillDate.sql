-- First we rank products by change_date in descending order and then select the latest price for each product.
-- If there is no price for a product before the given date, we set the price to 10.

with ranked_products as (
select product_id, new_price as price, change_date,
rank() over (partition by product_id order by change_date DESC) as prod_ranks
from Products
where change_date <= '2019-08-16')
select product_id, price
from ranked_products
where prod_ranks = 1

union

select product_id, 10 price
from Products
where product_id not in (
    select product_id from Products
where change_date <= '2019-08-16')
