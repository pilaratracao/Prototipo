export class AbstractRegister
{
    constructor()
    {
        if (this.constructor === AbstractRegister)
        {
            throw new Error("Abstract class can't be instantiated.");
        }

        this.register = [];
    }

    GetObjectById(id)
    {
        throw new Error("Method 'GetObjectById(id)' must be implemented.");
    }

    InsertObject(data, ws)
    {
        throw new Error("Method 'InsertObject()' must be implemented.");
    }

    DeleteObject(id)
    {
        throw new Error("Method 'DeleteObject(id)' must be implemented.");
    }

    removeItemOnce(arr, value){
        var index = arr.indexOf(value);
        if(index > -1){
            arr.splice(index, 1);
        };
        return;
    }
}