# Thing module
When Thing module is enabled you can make HTTP POSTs with arbitrarily structured JSON with an `id` property to the `/api/thing` endpoint. If you for example sent `{"id":"foo", "sensor1":42, "sensor2": 99}` to `/api/thing`, you would then find you have a View of that data at `/admin/content/data/view/thing_foo`. You can also make other Views out of your data by setting the `Show` property to your thing when creating a View instead of the usual `Content` option. Each column will then be available as field options.   


## How it works
When the Thing endpoint sees a JSON packet with a unique `id` property it has not seen before, it does the following.

1. Thing module creates a new table in the database where the tablename is `thing_{{id}}` with a schema of what it is in the JSON packet minus the id property.
2. Thing module tells the Data module to "adopt" this new table. 
3. Thing module creates a new node of type `thing` where the `field_thing_id` property is the same as the table name `thing_{{id}}`. 

When the Thing enpoint sees a JSON packet with an `id` property it has seen before, it saves that data in the corresponding table.


## Todo
- Save the first datapoint sent.
- Allow schema to change on subsequent JSON packets.


## Test
There is a test command that will send data every 5 seconds with an ID of `foo`.
```
./test <username> <password> <url without protocol>
```

Example:
```
./test pparker secretpass 127.0.0.1:8888
```
