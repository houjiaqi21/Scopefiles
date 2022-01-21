using Microsoft.SCOPE.Types;
using System;
using System.Collections.Generic;
using System.IO;
using System.Text;
using ScopeRuntime;
using ScopeRuntime.Diagnostics;

public class ImpressionProcessor : Processor
{
    /// <summary>
    /// 
    /// </summary>
    /// <param name="columns"></param>
    /// <param name="args"></param>
    /// <param name="input"></param>
    /// <returns></returns>
    public override Schema Produces(string[] columns, string[] args, Schema input)
    {
        return input.Clone();
    }
    /// <summary>
    ///
    /// </summary>
    /// <param name="input"></param>
    /// <param name="output"></param>
    /// <param name="args"></param>
    /// <returns></returns>    
    public override IEnumerable<Row> Process(RowSet input, Row output, string[] args)
    {

        foreach (Row row in input.Rows)
        {
            row.CopyTo(output);
            output[2].Set(10000000 / (row[200].Integer));
            if (row[2].Integer < 10000000)
            {
                DebugStream.WriteLine(String.Format("Impression = {0}", row[2].Integer));
            }
            //output[2].Set(10000000 / (row[2].Integer / 10000000));
            yield return output;
        }
    }
}