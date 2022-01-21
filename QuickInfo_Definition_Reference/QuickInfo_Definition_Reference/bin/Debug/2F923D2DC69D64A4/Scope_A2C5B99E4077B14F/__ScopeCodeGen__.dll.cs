using Microsoft.Analytics.Interfaces;
using System;
using System.Collections.Generic;
using System.Text;
using System.Reflection;
using System.IO;
using System.Text.RegularExpressions;
using System.Threading;
using System.Runtime.Serialization;
using System.Linq;
using Microsoft.SCOPE.Types;
using ScopeRuntime;
using ScopeRuntime.Diagnostics;
using System.Runtime.Versioning;
[assembly:TargetFramework(".NETFramework,Version=v4.7.2", FrameworkDisplayName = ".NET Framework, Version 4.7.2")]

public class ___Scope_Generated_Classes___
{
	public static int __RuntimeVersion__ = 0;
	public static int __WriteSStreamVersion__ = 3;
	public static bool __BondIntermediates__ = false;
	private delegate ColumnData ColumnDataCtor();
#region ==BEGIN USER CODE==
public class MyTSVExtractor : Extractor
{
    public override Schema Produces(string[] requested_columns, string[] args)
    {
        return new Schema(requested_columns);
    }

    public override IEnumerable<Row> Extract(StreamReader reader, Row output_row, string[] args)
    {
        char delimiter = '\t';
        string line;
        while ((line = reader.ReadLine()) != null)
        {
            var tokens = line.Split(delimiter);
            for (int i = 0; i < tokens.Length; ++i)
            {
                output_row[i].UnsafeSet(tokens[i]);
            }
            yield return output_row;
        }
    }
}

public class MyCSVOutputter : Outputter
{
    public override void Output(RowSet input, StreamWriter writer, string[] args)
    {
        foreach (Row row in input.Rows)
        {
            int c = 0;
            for (int i = 0; i < row.Count; i++)
            {
                if (c > 0)
                {
                    writer.Write(",");
                }
                row[i].Serialize(writer);
                c++;
            }
            writer.WriteLine();
            writer.Flush();
        }
    }
}

public class MyCombiner : Combiner
{
    private RowList _rowList = new RowList();

    public override Schema Produces(string[] requestedColumns, string[] args, Schema leftSchema, string leftTable, Schema rightSchema, string rightTable)
    {
        var tokens = new List<string>();

        foreach (var col in leftSchema.Columns)
        {
            string prefix = rightSchema.Contains(col.Name) ? leftTable : "";
            tokens.Add(string.Format("{0}{1}:{2}", prefix, col.Name, col.CLRType));
        }
        foreach (var col in rightSchema.Columns)
        {
            string prefix = leftSchema.Contains(col.Name) ? rightTable : "";
            tokens.Add(string.Format("{0}{1}:{2}", prefix, col.Name, col.CLRType));
        }
        var schemastring = String.Join(";", tokens);
        return new Schema(schemastring);
    }

    public override IEnumerable<Row> Combine(RowSet left, RowSet right, Row outputRow, string[] args)
    {
        _rowList.Load(right); //  Load the right RowSet into memory
        foreach (Row leftRow in left.Rows)
        {
            leftRow.CopyTo(outputRow); // Copy the data from the leftRow to the output

            //  Copy the data from the leftRow to the output
            foreach (Row rightRow in _rowList.Rows)
            {
                for (int i = 0; i < rightRow.Count; ++i)
                {
                    rightRow[i].CopyTo(outputRow[i + leftRow.Count]);
                }
                yield return outputRow;
            }
        }
    }


}

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
            output[2].Set(10000000 / (row[2].Integer));
            if (row[2].Integer < 10000000)
            {
                DebugStream.WriteLine(String.Format("Impression = {0}", row[2].Integer));
            }
            //output[2].Set(10000000 / (row[2].Integer / 10000000));
            yield return output;
        }
    }
}

public static class MyHelper
{
    public static int ParseDuration(string s)
    {
        string[] tokens = s.Split(new char[] { ':' });
        int hours_in_sec = int.Parse(tokens[0]) * 60 * 60;
        int minutes_in_sec = int.Parse(tokens[1]) * 60;
        int seconds = int.Parse(tokens[2]);
        int total = hours_in_sec + minutes_in_sec + seconds;
        return total;
    }

    public static double SecondsToHours(int seconds)
    {
        double hours = seconds / (60.0 * 60.0);
        return hours;
    }

    public static string FOO(string s)
    {
        return s.ToUpper();
    }

    public static string[] Split(string s, char c)
    {
        return s.Split(new char[] { c });
    }

    public static string Join(char c, IEnumerable<string> tokens)
    {
        var sb = new System.Text.StringBuilder();
        int n = 0;
        foreach (var token in tokens)
        {
            if (n > 0)
            {
                sb.Append(c);
            }
            sb.Append(token);
            n++;
        }
        return sb.ToString();
    }

}

public class UrlList
{
    public List<string> Items;
    private static char[] sepchars = new char[] { ',' };

    public UrlList(string s)
    {
        this.Items = new List<string>(s.Split(sepchars));
    }

    public static UrlList Create(string s)
    {
        return new UrlList(s);
    }

    public string Serialize()
    {
        return String.Join(";", this.Items);
    }
}

public class MySum_Double : Aggregate1<double, double>
{
    double sum = 0;
    public override void Initialize()
    {
        sum = 0;
    }

    public override void Add(double y)
    {
        sum += y;
    }

    public override double Finalize()
    {
        return sum;
    }
}

public class MyAgg2_IntegerDouble : Aggregate2<int, double, string>
{
    System.Text.StringBuilder sb;
    public override void Initialize()
    {
        sb = new System.Text.StringBuilder();
    }

    public override void Add(int count, double value)
    {
        for (int i = 0; i < count; i++)
        {
            sb.Append(value.ToString());
        }
    }

    public override string Finalize()
    {
        return sb.ToString();
    }
}

#endregion ==END USER CODE==

	public class Row_AdId_Integer_IId_Integer_Impression_Integer_IsClicked_Integer : Row
	{
		private static readonly System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>[] _columnTable = 
		{
			new System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>("AdId", ScopeRuntime.ColumnDataType.Integer, typeof(System.Int32), null, null),
			new System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>("IId", ScopeRuntime.ColumnDataType.Integer, typeof(System.Int32), null, null),
			new System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>("Impression", ScopeRuntime.ColumnDataType.Integer, typeof(System.Int32), null, null),
			new System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>("IsClicked", ScopeRuntime.ColumnDataType.Integer, typeof(System.Int32), null, null),
		};

		ScopeRuntime.IntegerColumnData s0_AdId;
		public ScopeRuntime.IntegerColumnData AdId
		{
			get { return s0_AdId; }
			set 
			{
				s0_AdId = value;
				_columns[0] = value;
			}
		}
		ScopeRuntime.IntegerColumnData s0_IId;
		public ScopeRuntime.IntegerColumnData IId
		{
			get { return s0_IId; }
			set 
			{
				s0_IId = value;
				_columns[1] = value;
			}
		}
		ScopeRuntime.IntegerColumnData s0_Impression;
		public ScopeRuntime.IntegerColumnData Impression
		{
			get { return s0_Impression; }
			set 
			{
				s0_Impression = value;
				_columns[2] = value;
			}
		}
		ScopeRuntime.IntegerColumnData s0_IsClicked;
		public ScopeRuntime.IntegerColumnData IsClicked
		{
			get { return s0_IsClicked; }
			set 
			{
				s0_IsClicked = value;
				_columns[3] = value;
			}
		}
		public Row_AdId_Integer_IId_Integer_Impression_Integer_IsClicked_Integer(Schema schema, ColumnData[] columns) : base(schema, columns) { }
		public Row_AdId_Integer_IId_Integer_Impression_Integer_IsClicked_Integer(Schema schema) : base(schema)
		{
			for (int i = 0; i < _columns.Length; ++i)
			{
				this[i] = _columns[i];
			}
		}
		public Row_AdId_Integer_IId_Integer_Impression_Integer_IsClicked_Integer() : base(BuildSchema(), BuildColumnData())
		{
			for (int i = 0; i < _columns.Length; ++i)
			{
				this[i] = _columns[i];
			}
		}
		private static Schema BuildSchema()
		{
			Schema schema = new Schema();
			for (int i = 0; i < _columnTable.Length; ++i)
			{
				if (_columnTable[i].Item5 == null)
				{
					schema.Add(new ScopeRuntime.ColumnInfo(_columnTable[i].Item1, _columnTable[i].Item3));
				}
				else
				{
					schema.Add(new ScopeRuntime.ColumnInfo(_columnTable[i].Item1, _columnTable[i].Item5));
				}
			}
			return schema;
		}
		private static ColumnData[] BuildColumnData()
		{
			ColumnData[] columnData = new ColumnData[_columnTable.Length];
			for (int i = 0; i < _columnTable.Length; ++i)
			{
				if (_columnTable[i].Item5 == null)
				{
					columnData[i] = _columnTable[i].Item4 != null ? _columnTable[i].Item4() : ColumnDataFactory.Create(_columnTable[i].Item2);
				}
				else
				{
					columnData[i] = ColumnDataFactory.CreateStruct(_columnTable[i].Item5);
				}
			}
			return columnData;
		}
		public override ColumnData this[int index]
		{
			get { return _columns[index]; }
			set
			{
				_columns[index] = value;

				//  We also need to reset the property
				switch (index)
				{

					case 0:
					{
						s0_AdId = (ScopeRuntime.IntegerColumnData)value;
						break;
					}
					case 1:
					{
						s0_IId = (ScopeRuntime.IntegerColumnData)value;
						break;
					}
					case 2:
					{
						s0_Impression = (ScopeRuntime.IntegerColumnData)value;
						break;
					}
					case 3:
					{
						s0_IsClicked = (ScopeRuntime.IntegerColumnData)value;
						break;
					}
				}
			}
		}
		public override void Serialize(BinaryWriter writer)
		{
			s0_AdId.Serialize(writer);
			s0_IId.Serialize(writer);
			s0_Impression.Serialize(writer);
			s0_IsClicked.Serialize(writer);
		}

		public override void Deserialize(BinaryReader reader)
		{
			s0_AdId.Deserialize(reader);
			s0_IId.Deserialize(reader);
			s0_Impression.Deserialize(reader);
			s0_IsClicked.Deserialize(reader);
		}
	}


	public class Row_AdId_Integer_IId_Integer_Impression_Integer : Row
	{
		private static readonly System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>[] _columnTable = 
		{
			new System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>("AdId", ScopeRuntime.ColumnDataType.Integer, typeof(System.Int32), null, null),
			new System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>("IId", ScopeRuntime.ColumnDataType.Integer, typeof(System.Int32), null, null),
			new System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>("Impression", ScopeRuntime.ColumnDataType.Integer, typeof(System.Int32), null, null),
		};

		ScopeRuntime.IntegerColumnData s0_AdId;
		public ScopeRuntime.IntegerColumnData AdId
		{
			get { return s0_AdId; }
			set 
			{
				s0_AdId = value;
				_columns[0] = value;
			}
		}
		ScopeRuntime.IntegerColumnData s0_IId;
		public ScopeRuntime.IntegerColumnData IId
		{
			get { return s0_IId; }
			set 
			{
				s0_IId = value;
				_columns[1] = value;
			}
		}
		ScopeRuntime.IntegerColumnData s0_Impression;
		public ScopeRuntime.IntegerColumnData Impression
		{
			get { return s0_Impression; }
			set 
			{
				s0_Impression = value;
				_columns[2] = value;
			}
		}
		public Row_AdId_Integer_IId_Integer_Impression_Integer(Schema schema, ColumnData[] columns) : base(schema, columns) { }
		public Row_AdId_Integer_IId_Integer_Impression_Integer(Schema schema) : base(schema)
		{
			for (int i = 0; i < _columns.Length; ++i)
			{
				this[i] = _columns[i];
			}
		}
		public Row_AdId_Integer_IId_Integer_Impression_Integer() : base(BuildSchema(), BuildColumnData())
		{
			for (int i = 0; i < _columns.Length; ++i)
			{
				this[i] = _columns[i];
			}
		}
		private static Schema BuildSchema()
		{
			Schema schema = new Schema();
			for (int i = 0; i < _columnTable.Length; ++i)
			{
				if (_columnTable[i].Item5 == null)
				{
					schema.Add(new ScopeRuntime.ColumnInfo(_columnTable[i].Item1, _columnTable[i].Item3));
				}
				else
				{
					schema.Add(new ScopeRuntime.ColumnInfo(_columnTable[i].Item1, _columnTable[i].Item5));
				}
			}
			return schema;
		}
		private static ColumnData[] BuildColumnData()
		{
			ColumnData[] columnData = new ColumnData[_columnTable.Length];
			for (int i = 0; i < _columnTable.Length; ++i)
			{
				if (_columnTable[i].Item5 == null)
				{
					columnData[i] = _columnTable[i].Item4 != null ? _columnTable[i].Item4() : ColumnDataFactory.Create(_columnTable[i].Item2);
				}
				else
				{
					columnData[i] = ColumnDataFactory.CreateStruct(_columnTable[i].Item5);
				}
			}
			return columnData;
		}
		public override ColumnData this[int index]
		{
			get { return _columns[index]; }
			set
			{
				_columns[index] = value;

				//  We also need to reset the property
				switch (index)
				{

					case 0:
					{
						s0_AdId = (ScopeRuntime.IntegerColumnData)value;
						break;
					}
					case 1:
					{
						s0_IId = (ScopeRuntime.IntegerColumnData)value;
						break;
					}
					case 2:
					{
						s0_Impression = (ScopeRuntime.IntegerColumnData)value;
						break;
					}
				}
			}
		}
		public override void Serialize(BinaryWriter writer)
		{
			s0_AdId.Serialize(writer);
			s0_IId.Serialize(writer);
			s0_Impression.Serialize(writer);
		}

		public override void Deserialize(BinaryReader reader)
		{
			s0_AdId.Deserialize(reader);
			s0_IId.Deserialize(reader);
			s0_Impression.Deserialize(reader);
		}
	}


	public class Row_2BFC241179AB532 : Row
	{
		private static readonly System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>[] _columnTable = 
		{
			new System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>("IId", ScopeRuntime.ColumnDataType.Integer, typeof(System.Int32), null, null),
			new System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>("UId", ScopeRuntime.ColumnDataType.Integer, typeof(System.Int32), null, null),
			new System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>("Start", ScopeRuntime.ColumnDataType.DateTime, typeof(System.DateTime), null, null),
			new System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>("Market", ScopeRuntime.ColumnDataType.String, typeof(System.String), null, null),
			new System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>("Query", ScopeRuntime.ColumnDataType.String, typeof(System.String), null, null),
			new System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>("DwellTime", ScopeRuntime.ColumnDataType.Integer, typeof(System.Int32), null, null),
			new System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>("Results", ScopeRuntime.ColumnDataType.String, typeof(System.String), null, null),
			new System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>("ClickedUrls", ScopeRuntime.ColumnDataType.String, typeof(System.String), null, null),
		};

		ScopeRuntime.IntegerColumnData s0_IId;
		public ScopeRuntime.IntegerColumnData IId
		{
			get { return s0_IId; }
			set 
			{
				s0_IId = value;
				_columns[0] = value;
			}
		}
		ScopeRuntime.IntegerColumnData s0_UId;
		public ScopeRuntime.IntegerColumnData UId
		{
			get { return s0_UId; }
			set 
			{
				s0_UId = value;
				_columns[1] = value;
			}
		}
		ScopeRuntime.DateTimeColumnData s0_Start;
		public ScopeRuntime.DateTimeColumnData Start
		{
			get { return s0_Start; }
			set 
			{
				s0_Start = value;
				_columns[2] = value;
			}
		}
		ScopeRuntime.StringColumnData s0_Market;
		public ScopeRuntime.StringColumnData Market
		{
			get { return s0_Market; }
			set 
			{
				s0_Market = value;
				_columns[3] = value;
			}
		}
		ScopeRuntime.StringColumnData s0_Query;
		public ScopeRuntime.StringColumnData Query
		{
			get { return s0_Query; }
			set 
			{
				s0_Query = value;
				_columns[4] = value;
			}
		}
		ScopeRuntime.IntegerColumnData s0_DwellTime;
		public ScopeRuntime.IntegerColumnData DwellTime
		{
			get { return s0_DwellTime; }
			set 
			{
				s0_DwellTime = value;
				_columns[5] = value;
			}
		}
		ScopeRuntime.StringColumnData s0_Results;
		public ScopeRuntime.StringColumnData Results
		{
			get { return s0_Results; }
			set 
			{
				s0_Results = value;
				_columns[6] = value;
			}
		}
		ScopeRuntime.StringColumnData s0_ClickedUrls;
		public ScopeRuntime.StringColumnData ClickedUrls
		{
			get { return s0_ClickedUrls; }
			set 
			{
				s0_ClickedUrls = value;
				_columns[7] = value;
			}
		}
		public Row_2BFC241179AB532(Schema schema, ColumnData[] columns) : base(schema, columns) { }
		public Row_2BFC241179AB532(Schema schema) : base(schema)
		{
			for (int i = 0; i < _columns.Length; ++i)
			{
				this[i] = _columns[i];
			}
		}
		public Row_2BFC241179AB532() : base(BuildSchema(), BuildColumnData())
		{
			for (int i = 0; i < _columns.Length; ++i)
			{
				this[i] = _columns[i];
			}
		}
		private static Schema BuildSchema()
		{
			Schema schema = new Schema();
			for (int i = 0; i < _columnTable.Length; ++i)
			{
				if (_columnTable[i].Item5 == null)
				{
					schema.Add(new ScopeRuntime.ColumnInfo(_columnTable[i].Item1, _columnTable[i].Item3));
				}
				else
				{
					schema.Add(new ScopeRuntime.ColumnInfo(_columnTable[i].Item1, _columnTable[i].Item5));
				}
			}
			return schema;
		}
		private static ColumnData[] BuildColumnData()
		{
			ColumnData[] columnData = new ColumnData[_columnTable.Length];
			for (int i = 0; i < _columnTable.Length; ++i)
			{
				if (_columnTable[i].Item5 == null)
				{
					columnData[i] = _columnTable[i].Item4 != null ? _columnTable[i].Item4() : ColumnDataFactory.Create(_columnTable[i].Item2);
				}
				else
				{
					columnData[i] = ColumnDataFactory.CreateStruct(_columnTable[i].Item5);
				}
			}
			return columnData;
		}
		public override ColumnData this[int index]
		{
			get { return _columns[index]; }
			set
			{
				_columns[index] = value;

				//  We also need to reset the property
				switch (index)
				{

					case 0:
					{
						s0_IId = (ScopeRuntime.IntegerColumnData)value;
						break;
					}
					case 1:
					{
						s0_UId = (ScopeRuntime.IntegerColumnData)value;
						break;
					}
					case 2:
					{
						s0_Start = (ScopeRuntime.DateTimeColumnData)value;
						break;
					}
					case 3:
					{
						s0_Market = (ScopeRuntime.StringColumnData)value;
						break;
					}
					case 4:
					{
						s0_Query = (ScopeRuntime.StringColumnData)value;
						break;
					}
					case 5:
					{
						s0_DwellTime = (ScopeRuntime.IntegerColumnData)value;
						break;
					}
					case 6:
					{
						s0_Results = (ScopeRuntime.StringColumnData)value;
						break;
					}
					case 7:
					{
						s0_ClickedUrls = (ScopeRuntime.StringColumnData)value;
						break;
					}
				}
			}
		}
		public override void Serialize(BinaryWriter writer)
		{
			byte[] ___masking___ = new byte[1];
			___masking___[0] = 1;

			bool hasNull = false;
			if (s0_Market.IsNull())
			{
				hasNull = true;
				___masking___[0] |= (byte)(1 << 1);
			}
			if (s0_Query.IsNull())
			{
				hasNull = true;
				___masking___[0] |= (byte)(1 << 2);
			}
			if (s0_Results.IsNull())
			{
				hasNull = true;
				___masking___[0] |= (byte)(1 << 3);
			}
			if (s0_ClickedUrls.IsNull())
			{
				hasNull = true;
				___masking___[0] |= (byte)(1 << 4);
			}
			if (hasNull)
			{
				writer.Write(___masking___[0]);
			}
			else
			{
				writer.Write( (byte) 0);
			}
			s0_IId.Serialize(writer);
			s0_UId.Serialize(writer);
			s0_Start.Serialize(writer);
			if (!s0_Market.IsNull())
			{
				s0_Market.Serialize(writer);
			}
			if (!s0_Query.IsNull())
			{
				s0_Query.Serialize(writer);
			}
			s0_DwellTime.Serialize(writer);
			if (!s0_Results.IsNull())
			{
				s0_Results.Serialize(writer);
			}
			if (!s0_ClickedUrls.IsNull())
			{
				s0_ClickedUrls.Serialize(writer);
			}
		}

		public override void Deserialize(BinaryReader reader)
		{
			byte[] ___masking___ = new byte[1];
			byte firstByte = reader.ReadByte();
			if (firstByte == 0)
			{
				s0_IId.Deserialize(reader);
				s0_UId.Deserialize(reader);
				s0_Start.Deserialize(reader);
				s0_Market.Deserialize(reader);
				s0_Query.Deserialize(reader);
				s0_DwellTime.Deserialize(reader);
				s0_Results.Deserialize(reader);
				s0_ClickedUrls.Deserialize(reader);
			}
			else
			{
				___masking___[0] = firstByte;
				s0_IId.Deserialize(reader);
				s0_UId.Deserialize(reader);
				s0_Start.Deserialize(reader);
				if ((___masking___[0] & 2) != 2)
				{
					s0_Market.Deserialize(reader);
				}
				else
				{
					s0_Market.SetNull();
				}
				if ((___masking___[0] & 4) != 4)
				{
					s0_Query.Deserialize(reader);
				}
				else
				{
					s0_Query.SetNull();
				}
				s0_DwellTime.Deserialize(reader);
				if ((___masking___[0] & 8) != 8)
				{
					s0_Results.Deserialize(reader);
				}
				else
				{
					s0_Results.SetNull();
				}
				if ((___masking___[0] & 16) != 16)
				{
					s0_ClickedUrls.Deserialize(reader);
				}
				else
				{
					s0_ClickedUrls.SetNull();
				}
			}
		}
	}


	public class Row_Query_String_IId1_Integer : Row
	{
		private static readonly System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>[] _columnTable = 
		{
			new System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>("Query", ScopeRuntime.ColumnDataType.String, typeof(System.String), null, null),
			new System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>("IId1", ScopeRuntime.ColumnDataType.Integer, typeof(System.Int32), null, null),
		};

		ScopeRuntime.StringColumnData s0_Query;
		public ScopeRuntime.StringColumnData Query
		{
			get { return s0_Query; }
			set 
			{
				s0_Query = value;
				_columns[0] = value;
			}
		}
		ScopeRuntime.IntegerColumnData s0_IId1;
		public ScopeRuntime.IntegerColumnData IId1
		{
			get { return s0_IId1; }
			set 
			{
				s0_IId1 = value;
				_columns[1] = value;
			}
		}
		public Row_Query_String_IId1_Integer(Schema schema, ColumnData[] columns) : base(schema, columns) { }
		public Row_Query_String_IId1_Integer(Schema schema) : base(schema)
		{
			for (int i = 0; i < _columns.Length; ++i)
			{
				this[i] = _columns[i];
			}
		}
		public Row_Query_String_IId1_Integer() : base(BuildSchema(), BuildColumnData())
		{
			for (int i = 0; i < _columns.Length; ++i)
			{
				this[i] = _columns[i];
			}
		}
		private static Schema BuildSchema()
		{
			Schema schema = new Schema();
			for (int i = 0; i < _columnTable.Length; ++i)
			{
				if (_columnTable[i].Item5 == null)
				{
					schema.Add(new ScopeRuntime.ColumnInfo(_columnTable[i].Item1, _columnTable[i].Item3));
				}
				else
				{
					schema.Add(new ScopeRuntime.ColumnInfo(_columnTable[i].Item1, _columnTable[i].Item5));
				}
			}
			return schema;
		}
		private static ColumnData[] BuildColumnData()
		{
			ColumnData[] columnData = new ColumnData[_columnTable.Length];
			for (int i = 0; i < _columnTable.Length; ++i)
			{
				if (_columnTable[i].Item5 == null)
				{
					columnData[i] = _columnTable[i].Item4 != null ? _columnTable[i].Item4() : ColumnDataFactory.Create(_columnTable[i].Item2);
				}
				else
				{
					columnData[i] = ColumnDataFactory.CreateStruct(_columnTable[i].Item5);
				}
			}
			return columnData;
		}
		public override ColumnData this[int index]
		{
			get { return _columns[index]; }
			set
			{
				_columns[index] = value;

				//  We also need to reset the property
				switch (index)
				{

					case 0:
					{
						s0_Query = (ScopeRuntime.StringColumnData)value;
						break;
					}
					case 1:
					{
						s0_IId1 = (ScopeRuntime.IntegerColumnData)value;
						break;
					}
				}
			}
		}
		public override void Serialize(BinaryWriter writer)
		{
			byte[] ___masking___ = new byte[1];
			___masking___[0] = 1;

			bool hasNull = false;
			if (s0_Query.IsNull())
			{
				hasNull = true;
				___masking___[0] |= (byte)(1 << 1);
			}
			if (hasNull)
			{
				writer.Write(___masking___[0]);
			}
			else
			{
				writer.Write( (byte) 0);
			}
			if (!s0_Query.IsNull())
			{
				s0_Query.Serialize(writer);
			}
			s0_IId1.Serialize(writer);
		}

		public override void Deserialize(BinaryReader reader)
		{
			byte[] ___masking___ = new byte[1];
			byte firstByte = reader.ReadByte();
			if (firstByte == 0)
			{
				s0_Query.Deserialize(reader);
				s0_IId1.Deserialize(reader);
			}
			else
			{
				___masking___[0] = firstByte;
				if ((___masking___[0] & 2) != 2)
				{
					s0_Query.Deserialize(reader);
				}
				else
				{
					s0_Query.SetNull();
				}
				s0_IId1.Deserialize(reader);
			}
		}
	}


	public class Row_AdId_Integer_IId_Integer_Impression_Integer_Query_String : Row
	{
		private static readonly System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>[] _columnTable = 
		{
			new System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>("AdId", ScopeRuntime.ColumnDataType.Integer, typeof(System.Int32), null, null),
			new System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>("IId", ScopeRuntime.ColumnDataType.Integer, typeof(System.Int32), null, null),
			new System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>("Impression", ScopeRuntime.ColumnDataType.Integer, typeof(System.Int32), null, null),
			new System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>("Query", ScopeRuntime.ColumnDataType.String, typeof(System.String), null, null),
		};

		ScopeRuntime.IntegerColumnData s0_AdId;
		public ScopeRuntime.IntegerColumnData AdId
		{
			get { return s0_AdId; }
			set 
			{
				s0_AdId = value;
				_columns[0] = value;
			}
		}
		ScopeRuntime.IntegerColumnData s0_IId;
		public ScopeRuntime.IntegerColumnData IId
		{
			get { return s0_IId; }
			set 
			{
				s0_IId = value;
				_columns[1] = value;
			}
		}
		ScopeRuntime.IntegerColumnData s0_Impression;
		public ScopeRuntime.IntegerColumnData Impression
		{
			get { return s0_Impression; }
			set 
			{
				s0_Impression = value;
				_columns[2] = value;
			}
		}
		ScopeRuntime.StringColumnData s0_Query;
		public ScopeRuntime.StringColumnData Query
		{
			get { return s0_Query; }
			set 
			{
				s0_Query = value;
				_columns[3] = value;
			}
		}
		public Row_AdId_Integer_IId_Integer_Impression_Integer_Query_String(Schema schema, ColumnData[] columns) : base(schema, columns) { }
		public Row_AdId_Integer_IId_Integer_Impression_Integer_Query_String(Schema schema) : base(schema)
		{
			for (int i = 0; i < _columns.Length; ++i)
			{
				this[i] = _columns[i];
			}
		}
		public Row_AdId_Integer_IId_Integer_Impression_Integer_Query_String() : base(BuildSchema(), BuildColumnData())
		{
			for (int i = 0; i < _columns.Length; ++i)
			{
				this[i] = _columns[i];
			}
		}
		private static Schema BuildSchema()
		{
			Schema schema = new Schema();
			for (int i = 0; i < _columnTable.Length; ++i)
			{
				if (_columnTable[i].Item5 == null)
				{
					schema.Add(new ScopeRuntime.ColumnInfo(_columnTable[i].Item1, _columnTable[i].Item3));
				}
				else
				{
					schema.Add(new ScopeRuntime.ColumnInfo(_columnTable[i].Item1, _columnTable[i].Item5));
				}
			}
			return schema;
		}
		private static ColumnData[] BuildColumnData()
		{
			ColumnData[] columnData = new ColumnData[_columnTable.Length];
			for (int i = 0; i < _columnTable.Length; ++i)
			{
				if (_columnTable[i].Item5 == null)
				{
					columnData[i] = _columnTable[i].Item4 != null ? _columnTable[i].Item4() : ColumnDataFactory.Create(_columnTable[i].Item2);
				}
				else
				{
					columnData[i] = ColumnDataFactory.CreateStruct(_columnTable[i].Item5);
				}
			}
			return columnData;
		}
		public override ColumnData this[int index]
		{
			get { return _columns[index]; }
			set
			{
				_columns[index] = value;

				//  We also need to reset the property
				switch (index)
				{

					case 0:
					{
						s0_AdId = (ScopeRuntime.IntegerColumnData)value;
						break;
					}
					case 1:
					{
						s0_IId = (ScopeRuntime.IntegerColumnData)value;
						break;
					}
					case 2:
					{
						s0_Impression = (ScopeRuntime.IntegerColumnData)value;
						break;
					}
					case 3:
					{
						s0_Query = (ScopeRuntime.StringColumnData)value;
						break;
					}
				}
			}
		}
		public override void Serialize(BinaryWriter writer)
		{
			byte[] ___masking___ = new byte[1];
			___masking___[0] = 1;

			bool hasNull = false;
			if (s0_Query.IsNull())
			{
				hasNull = true;
				___masking___[0] |= (byte)(1 << 1);
			}
			if (hasNull)
			{
				writer.Write(___masking___[0]);
			}
			else
			{
				writer.Write( (byte) 0);
			}
			s0_AdId.Serialize(writer);
			s0_IId.Serialize(writer);
			s0_Impression.Serialize(writer);
			if (!s0_Query.IsNull())
			{
				s0_Query.Serialize(writer);
			}
		}

		public override void Deserialize(BinaryReader reader)
		{
			byte[] ___masking___ = new byte[1];
			byte firstByte = reader.ReadByte();
			if (firstByte == 0)
			{
				s0_AdId.Deserialize(reader);
				s0_IId.Deserialize(reader);
				s0_Impression.Deserialize(reader);
				s0_Query.Deserialize(reader);
			}
			else
			{
				___masking___[0] = firstByte;
				s0_AdId.Deserialize(reader);
				s0_IId.Deserialize(reader);
				s0_Impression.Deserialize(reader);
				if ((___masking___[0] & 2) != 2)
				{
					s0_Query.Deserialize(reader);
				}
				else
				{
					s0_Query.SetNull();
				}
			}
		}
	}


	public class Row_Market_String_DwellTime_Integer_Results_String : Row
	{
		private static readonly System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>[] _columnTable = 
		{
			new System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>("Market", ScopeRuntime.ColumnDataType.String, typeof(System.String), null, null),
			new System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>("DwellTime", ScopeRuntime.ColumnDataType.Integer, typeof(System.Int32), null, null),
			new System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>("Results", ScopeRuntime.ColumnDataType.String, typeof(System.String), null, null),
		};

		ScopeRuntime.StringColumnData s0_Market;
		public ScopeRuntime.StringColumnData Market
		{
			get { return s0_Market; }
			set 
			{
				s0_Market = value;
				_columns[0] = value;
			}
		}
		ScopeRuntime.IntegerColumnData s0_DwellTime;
		public ScopeRuntime.IntegerColumnData DwellTime
		{
			get { return s0_DwellTime; }
			set 
			{
				s0_DwellTime = value;
				_columns[1] = value;
			}
		}
		ScopeRuntime.StringColumnData s0_Results;
		public ScopeRuntime.StringColumnData Results
		{
			get { return s0_Results; }
			set 
			{
				s0_Results = value;
				_columns[2] = value;
			}
		}
		public Row_Market_String_DwellTime_Integer_Results_String(Schema schema, ColumnData[] columns) : base(schema, columns) { }
		public Row_Market_String_DwellTime_Integer_Results_String(Schema schema) : base(schema)
		{
			for (int i = 0; i < _columns.Length; ++i)
			{
				this[i] = _columns[i];
			}
		}
		public Row_Market_String_DwellTime_Integer_Results_String() : base(BuildSchema(), BuildColumnData())
		{
			for (int i = 0; i < _columns.Length; ++i)
			{
				this[i] = _columns[i];
			}
		}
		private static Schema BuildSchema()
		{
			Schema schema = new Schema();
			for (int i = 0; i < _columnTable.Length; ++i)
			{
				if (_columnTable[i].Item5 == null)
				{
					schema.Add(new ScopeRuntime.ColumnInfo(_columnTable[i].Item1, _columnTable[i].Item3));
				}
				else
				{
					schema.Add(new ScopeRuntime.ColumnInfo(_columnTable[i].Item1, _columnTable[i].Item5));
				}
			}
			return schema;
		}
		private static ColumnData[] BuildColumnData()
		{
			ColumnData[] columnData = new ColumnData[_columnTable.Length];
			for (int i = 0; i < _columnTable.Length; ++i)
			{
				if (_columnTable[i].Item5 == null)
				{
					columnData[i] = _columnTable[i].Item4 != null ? _columnTable[i].Item4() : ColumnDataFactory.Create(_columnTable[i].Item2);
				}
				else
				{
					columnData[i] = ColumnDataFactory.CreateStruct(_columnTable[i].Item5);
				}
			}
			return columnData;
		}
		public override ColumnData this[int index]
		{
			get { return _columns[index]; }
			set
			{
				_columns[index] = value;

				//  We also need to reset the property
				switch (index)
				{

					case 0:
					{
						s0_Market = (ScopeRuntime.StringColumnData)value;
						break;
					}
					case 1:
					{
						s0_DwellTime = (ScopeRuntime.IntegerColumnData)value;
						break;
					}
					case 2:
					{
						s0_Results = (ScopeRuntime.StringColumnData)value;
						break;
					}
				}
			}
		}
		public override void Serialize(BinaryWriter writer)
		{
			byte[] ___masking___ = new byte[1];
			___masking___[0] = 1;

			bool hasNull = false;
			if (s0_Market.IsNull())
			{
				hasNull = true;
				___masking___[0] |= (byte)(1 << 1);
			}
			if (s0_Results.IsNull())
			{
				hasNull = true;
				___masking___[0] |= (byte)(1 << 2);
			}
			if (hasNull)
			{
				writer.Write(___masking___[0]);
			}
			else
			{
				writer.Write( (byte) 0);
			}
			if (!s0_Market.IsNull())
			{
				s0_Market.Serialize(writer);
			}
			s0_DwellTime.Serialize(writer);
			if (!s0_Results.IsNull())
			{
				s0_Results.Serialize(writer);
			}
		}

		public override void Deserialize(BinaryReader reader)
		{
			byte[] ___masking___ = new byte[1];
			byte firstByte = reader.ReadByte();
			if (firstByte == 0)
			{
				s0_Market.Deserialize(reader);
				s0_DwellTime.Deserialize(reader);
				s0_Results.Deserialize(reader);
			}
			else
			{
				___masking___[0] = firstByte;
				if ((___masking___[0] & 2) != 2)
				{
					s0_Market.Deserialize(reader);
				}
				else
				{
					s0_Market.SetNull();
				}
				s0_DwellTime.Deserialize(reader);
				if ((___masking___[0] & 4) != 4)
				{
					s0_Results.Deserialize(reader);
				}
				else
				{
					s0_Results.SetNull();
				}
			}
		}
	}


	public class Row_DwellTimeDouble_Double_Market_String_Results_String : Row
	{
		private static readonly System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>[] _columnTable = 
		{
			new System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>("DwellTimeDouble", ScopeRuntime.ColumnDataType.Double, typeof(System.Double), null, null),
			new System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>("Market", ScopeRuntime.ColumnDataType.String, typeof(System.String), null, null),
			new System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>("Results", ScopeRuntime.ColumnDataType.String, typeof(System.String), null, null),
		};

		ScopeRuntime.DoubleColumnData s0_DwellTimeDouble;
		public ScopeRuntime.DoubleColumnData DwellTimeDouble
		{
			get { return s0_DwellTimeDouble; }
			set 
			{
				s0_DwellTimeDouble = value;
				_columns[0] = value;
			}
		}
		ScopeRuntime.StringColumnData s0_Market;
		public ScopeRuntime.StringColumnData Market
		{
			get { return s0_Market; }
			set 
			{
				s0_Market = value;
				_columns[1] = value;
			}
		}
		ScopeRuntime.StringColumnData s0_Results;
		public ScopeRuntime.StringColumnData Results
		{
			get { return s0_Results; }
			set 
			{
				s0_Results = value;
				_columns[2] = value;
			}
		}
		public Row_DwellTimeDouble_Double_Market_String_Results_String(Schema schema, ColumnData[] columns) : base(schema, columns) { }
		public Row_DwellTimeDouble_Double_Market_String_Results_String(Schema schema) : base(schema)
		{
			for (int i = 0; i < _columns.Length; ++i)
			{
				this[i] = _columns[i];
			}
		}
		public Row_DwellTimeDouble_Double_Market_String_Results_String() : base(BuildSchema(), BuildColumnData())
		{
			for (int i = 0; i < _columns.Length; ++i)
			{
				this[i] = _columns[i];
			}
		}
		private static Schema BuildSchema()
		{
			Schema schema = new Schema();
			for (int i = 0; i < _columnTable.Length; ++i)
			{
				if (_columnTable[i].Item5 == null)
				{
					schema.Add(new ScopeRuntime.ColumnInfo(_columnTable[i].Item1, _columnTable[i].Item3));
				}
				else
				{
					schema.Add(new ScopeRuntime.ColumnInfo(_columnTable[i].Item1, _columnTable[i].Item5));
				}
			}
			return schema;
		}
		private static ColumnData[] BuildColumnData()
		{
			ColumnData[] columnData = new ColumnData[_columnTable.Length];
			for (int i = 0; i < _columnTable.Length; ++i)
			{
				if (_columnTable[i].Item5 == null)
				{
					columnData[i] = _columnTable[i].Item4 != null ? _columnTable[i].Item4() : ColumnDataFactory.Create(_columnTable[i].Item2);
				}
				else
				{
					columnData[i] = ColumnDataFactory.CreateStruct(_columnTable[i].Item5);
				}
			}
			return columnData;
		}
		public override ColumnData this[int index]
		{
			get { return _columns[index]; }
			set
			{
				_columns[index] = value;

				//  We also need to reset the property
				switch (index)
				{

					case 0:
					{
						s0_DwellTimeDouble = (ScopeRuntime.DoubleColumnData)value;
						break;
					}
					case 1:
					{
						s0_Market = (ScopeRuntime.StringColumnData)value;
						break;
					}
					case 2:
					{
						s0_Results = (ScopeRuntime.StringColumnData)value;
						break;
					}
				}
			}
		}
		public override void Serialize(BinaryWriter writer)
		{
			byte[] ___masking___ = new byte[1];
			___masking___[0] = 1;

			bool hasNull = false;
			if (s0_Market.IsNull())
			{
				hasNull = true;
				___masking___[0] |= (byte)(1 << 1);
			}
			if (s0_Results.IsNull())
			{
				hasNull = true;
				___masking___[0] |= (byte)(1 << 2);
			}
			if (hasNull)
			{
				writer.Write(___masking___[0]);
			}
			else
			{
				writer.Write( (byte) 0);
			}
			s0_DwellTimeDouble.Serialize(writer);
			if (!s0_Market.IsNull())
			{
				s0_Market.Serialize(writer);
			}
			if (!s0_Results.IsNull())
			{
				s0_Results.Serialize(writer);
			}
		}

		public override void Deserialize(BinaryReader reader)
		{
			byte[] ___masking___ = new byte[1];
			byte firstByte = reader.ReadByte();
			if (firstByte == 0)
			{
				s0_DwellTimeDouble.Deserialize(reader);
				s0_Market.Deserialize(reader);
				s0_Results.Deserialize(reader);
			}
			else
			{
				___masking___[0] = firstByte;
				s0_DwellTimeDouble.Deserialize(reader);
				if ((___masking___[0] & 2) != 2)
				{
					s0_Market.Deserialize(reader);
				}
				else
				{
					s0_Market.SetNull();
				}
				if ((___masking___[0] & 4) != 4)
				{
					s0_Results.Deserialize(reader);
				}
				else
				{
					s0_Results.SetNull();
				}
			}
		}
	}


	public class Row_Market_String_Results_String : Row
	{
		private static readonly System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>[] _columnTable = 
		{
			new System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>("Market", ScopeRuntime.ColumnDataType.String, typeof(System.String), null, null),
			new System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>("Results", ScopeRuntime.ColumnDataType.String, typeof(System.String), null, null),
		};

		ScopeRuntime.StringColumnData s0_Market;
		public ScopeRuntime.StringColumnData Market
		{
			get { return s0_Market; }
			set 
			{
				s0_Market = value;
				_columns[0] = value;
			}
		}
		ScopeRuntime.StringColumnData s0_Results;
		public ScopeRuntime.StringColumnData Results
		{
			get { return s0_Results; }
			set 
			{
				s0_Results = value;
				_columns[1] = value;
			}
		}
		public Row_Market_String_Results_String(Schema schema, ColumnData[] columns) : base(schema, columns) { }
		public Row_Market_String_Results_String(Schema schema) : base(schema)
		{
			for (int i = 0; i < _columns.Length; ++i)
			{
				this[i] = _columns[i];
			}
		}
		public Row_Market_String_Results_String() : base(BuildSchema(), BuildColumnData())
		{
			for (int i = 0; i < _columns.Length; ++i)
			{
				this[i] = _columns[i];
			}
		}
		private static Schema BuildSchema()
		{
			Schema schema = new Schema();
			for (int i = 0; i < _columnTable.Length; ++i)
			{
				if (_columnTable[i].Item5 == null)
				{
					schema.Add(new ScopeRuntime.ColumnInfo(_columnTable[i].Item1, _columnTable[i].Item3));
				}
				else
				{
					schema.Add(new ScopeRuntime.ColumnInfo(_columnTable[i].Item1, _columnTable[i].Item5));
				}
			}
			return schema;
		}
		private static ColumnData[] BuildColumnData()
		{
			ColumnData[] columnData = new ColumnData[_columnTable.Length];
			for (int i = 0; i < _columnTable.Length; ++i)
			{
				if (_columnTable[i].Item5 == null)
				{
					columnData[i] = _columnTable[i].Item4 != null ? _columnTable[i].Item4() : ColumnDataFactory.Create(_columnTable[i].Item2);
				}
				else
				{
					columnData[i] = ColumnDataFactory.CreateStruct(_columnTable[i].Item5);
				}
			}
			return columnData;
		}
		public override ColumnData this[int index]
		{
			get { return _columns[index]; }
			set
			{
				_columns[index] = value;

				//  We also need to reset the property
				switch (index)
				{

					case 0:
					{
						s0_Market = (ScopeRuntime.StringColumnData)value;
						break;
					}
					case 1:
					{
						s0_Results = (ScopeRuntime.StringColumnData)value;
						break;
					}
				}
			}
		}
		public override void Serialize(BinaryWriter writer)
		{
			byte[] ___masking___ = new byte[1];
			___masking___[0] = 1;

			bool hasNull = false;
			if (s0_Market.IsNull())
			{
				hasNull = true;
				___masking___[0] |= (byte)(1 << 1);
			}
			if (s0_Results.IsNull())
			{
				hasNull = true;
				___masking___[0] |= (byte)(1 << 2);
			}
			if (hasNull)
			{
				writer.Write(___masking___[0]);
			}
			else
			{
				writer.Write( (byte) 0);
			}
			if (!s0_Market.IsNull())
			{
				s0_Market.Serialize(writer);
			}
			if (!s0_Results.IsNull())
			{
				s0_Results.Serialize(writer);
			}
		}

		public override void Deserialize(BinaryReader reader)
		{
			byte[] ___masking___ = new byte[1];
			byte firstByte = reader.ReadByte();
			if (firstByte == 0)
			{
				s0_Market.Deserialize(reader);
				s0_Results.Deserialize(reader);
			}
			else
			{
				___masking___[0] = firstByte;
				if ((___masking___[0] & 2) != 2)
				{
					s0_Market.Deserialize(reader);
				}
				else
				{
					s0_Market.SetNull();
				}
				if ((___masking___[0] & 4) != 4)
				{
					s0_Results.Deserialize(reader);
				}
				else
				{
					s0_Results.SetNull();
				}
			}
		}
	}


	public class Row_Market_String_SplitResult_String : Row
	{
		private static readonly System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>[] _columnTable = 
		{
			new System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>("Market", ScopeRuntime.ColumnDataType.String, typeof(System.String), null, null),
			new System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>("SplitResult", ScopeRuntime.ColumnDataType.String, typeof(System.String), null, null),
		};

		ScopeRuntime.StringColumnData s0_Market;
		public ScopeRuntime.StringColumnData Market
		{
			get { return s0_Market; }
			set 
			{
				s0_Market = value;
				_columns[0] = value;
			}
		}
		ScopeRuntime.StringColumnData s0_SplitResult;
		public ScopeRuntime.StringColumnData SplitResult
		{
			get { return s0_SplitResult; }
			set 
			{
				s0_SplitResult = value;
				_columns[1] = value;
			}
		}
		public Row_Market_String_SplitResult_String(Schema schema, ColumnData[] columns) : base(schema, columns) { }
		public Row_Market_String_SplitResult_String(Schema schema) : base(schema)
		{
			for (int i = 0; i < _columns.Length; ++i)
			{
				this[i] = _columns[i];
			}
		}
		public Row_Market_String_SplitResult_String() : base(BuildSchema(), BuildColumnData())
		{
			for (int i = 0; i < _columns.Length; ++i)
			{
				this[i] = _columns[i];
			}
		}
		private static Schema BuildSchema()
		{
			Schema schema = new Schema();
			for (int i = 0; i < _columnTable.Length; ++i)
			{
				if (_columnTable[i].Item5 == null)
				{
					schema.Add(new ScopeRuntime.ColumnInfo(_columnTable[i].Item1, _columnTable[i].Item3));
				}
				else
				{
					schema.Add(new ScopeRuntime.ColumnInfo(_columnTable[i].Item1, _columnTable[i].Item5));
				}
			}
			return schema;
		}
		private static ColumnData[] BuildColumnData()
		{
			ColumnData[] columnData = new ColumnData[_columnTable.Length];
			for (int i = 0; i < _columnTable.Length; ++i)
			{
				if (_columnTable[i].Item5 == null)
				{
					columnData[i] = _columnTable[i].Item4 != null ? _columnTable[i].Item4() : ColumnDataFactory.Create(_columnTable[i].Item2);
				}
				else
				{
					columnData[i] = ColumnDataFactory.CreateStruct(_columnTable[i].Item5);
				}
			}
			return columnData;
		}
		public override ColumnData this[int index]
		{
			get { return _columns[index]; }
			set
			{
				_columns[index] = value;

				//  We also need to reset the property
				switch (index)
				{

					case 0:
					{
						s0_Market = (ScopeRuntime.StringColumnData)value;
						break;
					}
					case 1:
					{
						s0_SplitResult = (ScopeRuntime.StringColumnData)value;
						break;
					}
				}
			}
		}
		public override void Serialize(BinaryWriter writer)
		{
			byte[] ___masking___ = new byte[1];
			___masking___[0] = 1;

			bool hasNull = false;
			if (s0_Market.IsNull())
			{
				hasNull = true;
				___masking___[0] |= (byte)(1 << 1);
			}
			if (s0_SplitResult.IsNull())
			{
				hasNull = true;
				___masking___[0] |= (byte)(1 << 2);
			}
			if (hasNull)
			{
				writer.Write(___masking___[0]);
			}
			else
			{
				writer.Write( (byte) 0);
			}
			if (!s0_Market.IsNull())
			{
				s0_Market.Serialize(writer);
			}
			if (!s0_SplitResult.IsNull())
			{
				s0_SplitResult.Serialize(writer);
			}
		}

		public override void Deserialize(BinaryReader reader)
		{
			byte[] ___masking___ = new byte[1];
			byte firstByte = reader.ReadByte();
			if (firstByte == 0)
			{
				s0_Market.Deserialize(reader);
				s0_SplitResult.Deserialize(reader);
			}
			else
			{
				___masking___[0] = firstByte;
				if ((___masking___[0] & 2) != 2)
				{
					s0_Market.Deserialize(reader);
				}
				else
				{
					s0_Market.SetNull();
				}
				if ((___masking___[0] & 4) != 4)
				{
					s0_SplitResult.Deserialize(reader);
				}
				else
				{
					s0_SplitResult.SetNull();
				}
			}
		}
	}



public class ScopeCrossApplyProcessor_1 : Processor
{
    public override Schema Produces(string[] columns, string[] args, Schema input)
    {
       return new Schema("Market:string,SplitResult:string");
    }

    public override IEnumerable<Row> Process(RowSet input, Row outputRow, string[] args)
    {
        var nativeOutputRow = (Row_Market_String_SplitResult_String)outputRow;
        foreach (Row_Market_String_Results_String row in input.Rows)
        {
            System.String Market = row.Market.String;
                nativeOutputRow.Market.Set(Market);
            System.String Results = row.Results.String;
            var _crossApplyReturn = MyHelper.Split(Results, ';');
            if ( _crossApplyReturn != null )
            {
                foreach(var col in _crossApplyReturn )
                {
                nativeOutputRow.SplitResult.Set(col);
                yield return nativeOutputRow;
                }
            }
        }
    }
};


	public class Row_Market_String_Result_String : Row
	{
		private static readonly System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>[] _columnTable = 
		{
			new System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>("Market", ScopeRuntime.ColumnDataType.String, typeof(System.String), null, null),
			new System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>("Result", ScopeRuntime.ColumnDataType.String, typeof(System.String), null, null),
		};

		ScopeRuntime.StringColumnData s0_Market;
		public ScopeRuntime.StringColumnData Market
		{
			get { return s0_Market; }
			set 
			{
				s0_Market = value;
				_columns[0] = value;
			}
		}
		ScopeRuntime.StringColumnData s0_Result;
		public ScopeRuntime.StringColumnData Result
		{
			get { return s0_Result; }
			set 
			{
				s0_Result = value;
				_columns[1] = value;
			}
		}
		public Row_Market_String_Result_String(Schema schema, ColumnData[] columns) : base(schema, columns) { }
		public Row_Market_String_Result_String(Schema schema) : base(schema)
		{
			for (int i = 0; i < _columns.Length; ++i)
			{
				this[i] = _columns[i];
			}
		}
		public Row_Market_String_Result_String() : base(BuildSchema(), BuildColumnData())
		{
			for (int i = 0; i < _columns.Length; ++i)
			{
				this[i] = _columns[i];
			}
		}
		private static Schema BuildSchema()
		{
			Schema schema = new Schema();
			for (int i = 0; i < _columnTable.Length; ++i)
			{
				if (_columnTable[i].Item5 == null)
				{
					schema.Add(new ScopeRuntime.ColumnInfo(_columnTable[i].Item1, _columnTable[i].Item3));
				}
				else
				{
					schema.Add(new ScopeRuntime.ColumnInfo(_columnTable[i].Item1, _columnTable[i].Item5));
				}
			}
			return schema;
		}
		private static ColumnData[] BuildColumnData()
		{
			ColumnData[] columnData = new ColumnData[_columnTable.Length];
			for (int i = 0; i < _columnTable.Length; ++i)
			{
				if (_columnTable[i].Item5 == null)
				{
					columnData[i] = _columnTable[i].Item4 != null ? _columnTable[i].Item4() : ColumnDataFactory.Create(_columnTable[i].Item2);
				}
				else
				{
					columnData[i] = ColumnDataFactory.CreateStruct(_columnTable[i].Item5);
				}
			}
			return columnData;
		}
		public override ColumnData this[int index]
		{
			get { return _columns[index]; }
			set
			{
				_columns[index] = value;

				//  We also need to reset the property
				switch (index)
				{

					case 0:
					{
						s0_Market = (ScopeRuntime.StringColumnData)value;
						break;
					}
					case 1:
					{
						s0_Result = (ScopeRuntime.StringColumnData)value;
						break;
					}
				}
			}
		}
		public override void Serialize(BinaryWriter writer)
		{
			byte[] ___masking___ = new byte[1];
			___masking___[0] = 1;

			bool hasNull = false;
			if (s0_Market.IsNull())
			{
				hasNull = true;
				___masking___[0] |= (byte)(1 << 1);
			}
			if (s0_Result.IsNull())
			{
				hasNull = true;
				___masking___[0] |= (byte)(1 << 2);
			}
			if (hasNull)
			{
				writer.Write(___masking___[0]);
			}
			else
			{
				writer.Write( (byte) 0);
			}
			if (!s0_Market.IsNull())
			{
				s0_Market.Serialize(writer);
			}
			if (!s0_Result.IsNull())
			{
				s0_Result.Serialize(writer);
			}
		}

		public override void Deserialize(BinaryReader reader)
		{
			byte[] ___masking___ = new byte[1];
			byte firstByte = reader.ReadByte();
			if (firstByte == 0)
			{
				s0_Market.Deserialize(reader);
				s0_Result.Deserialize(reader);
			}
			else
			{
				___masking___[0] = firstByte;
				if ((___masking___[0] & 2) != 2)
				{
					s0_Market.Deserialize(reader);
				}
				else
				{
					s0_Market.SetNull();
				}
				if ((___masking___[0] & 4) != 4)
				{
					s0_Result.Deserialize(reader);
				}
				else
				{
					s0_Result.SetNull();
				}
			}
		}
	}


	public class Row_Market_String_DwellTimeDouble_Double : Row
	{
		private static readonly System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>[] _columnTable = 
		{
			new System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>("Market", ScopeRuntime.ColumnDataType.String, typeof(System.String), null, null),
			new System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>("DwellTimeDouble", ScopeRuntime.ColumnDataType.Double, typeof(System.Double), null, null),
		};

		ScopeRuntime.StringColumnData s0_Market;
		public ScopeRuntime.StringColumnData Market
		{
			get { return s0_Market; }
			set 
			{
				s0_Market = value;
				_columns[0] = value;
			}
		}
		ScopeRuntime.DoubleColumnData s0_DwellTimeDouble;
		public ScopeRuntime.DoubleColumnData DwellTimeDouble
		{
			get { return s0_DwellTimeDouble; }
			set 
			{
				s0_DwellTimeDouble = value;
				_columns[1] = value;
			}
		}
		public Row_Market_String_DwellTimeDouble_Double(Schema schema, ColumnData[] columns) : base(schema, columns) { }
		public Row_Market_String_DwellTimeDouble_Double(Schema schema) : base(schema)
		{
			for (int i = 0; i < _columns.Length; ++i)
			{
				this[i] = _columns[i];
			}
		}
		public Row_Market_String_DwellTimeDouble_Double() : base(BuildSchema(), BuildColumnData())
		{
			for (int i = 0; i < _columns.Length; ++i)
			{
				this[i] = _columns[i];
			}
		}
		private static Schema BuildSchema()
		{
			Schema schema = new Schema();
			for (int i = 0; i < _columnTable.Length; ++i)
			{
				if (_columnTable[i].Item5 == null)
				{
					schema.Add(new ScopeRuntime.ColumnInfo(_columnTable[i].Item1, _columnTable[i].Item3));
				}
				else
				{
					schema.Add(new ScopeRuntime.ColumnInfo(_columnTable[i].Item1, _columnTable[i].Item5));
				}
			}
			return schema;
		}
		private static ColumnData[] BuildColumnData()
		{
			ColumnData[] columnData = new ColumnData[_columnTable.Length];
			for (int i = 0; i < _columnTable.Length; ++i)
			{
				if (_columnTable[i].Item5 == null)
				{
					columnData[i] = _columnTable[i].Item4 != null ? _columnTable[i].Item4() : ColumnDataFactory.Create(_columnTable[i].Item2);
				}
				else
				{
					columnData[i] = ColumnDataFactory.CreateStruct(_columnTable[i].Item5);
				}
			}
			return columnData;
		}
		public override ColumnData this[int index]
		{
			get { return _columns[index]; }
			set
			{
				_columns[index] = value;

				//  We also need to reset the property
				switch (index)
				{

					case 0:
					{
						s0_Market = (ScopeRuntime.StringColumnData)value;
						break;
					}
					case 1:
					{
						s0_DwellTimeDouble = (ScopeRuntime.DoubleColumnData)value;
						break;
					}
				}
			}
		}
		public override void Serialize(BinaryWriter writer)
		{
			byte[] ___masking___ = new byte[1];
			___masking___[0] = 1;

			bool hasNull = false;
			if (s0_Market.IsNull())
			{
				hasNull = true;
				___masking___[0] |= (byte)(1 << 1);
			}
			if (hasNull)
			{
				writer.Write(___masking___[0]);
			}
			else
			{
				writer.Write( (byte) 0);
			}
			if (!s0_Market.IsNull())
			{
				s0_Market.Serialize(writer);
			}
			s0_DwellTimeDouble.Serialize(writer);
		}

		public override void Deserialize(BinaryReader reader)
		{
			byte[] ___masking___ = new byte[1];
			byte firstByte = reader.ReadByte();
			if (firstByte == 0)
			{
				s0_Market.Deserialize(reader);
				s0_DwellTimeDouble.Deserialize(reader);
			}
			else
			{
				___masking___[0] = firstByte;
				if ((___masking___[0] & 2) != 2)
				{
					s0_Market.Deserialize(reader);
				}
				else
				{
					s0_Market.SetNull();
				}
				s0_DwellTimeDouble.Deserialize(reader);
			}
		}
	}


	public class Row_Market_String_TotalDwellTime_Double : Row
	{
		private static readonly System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>[] _columnTable = 
		{
			new System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>("Market", ScopeRuntime.ColumnDataType.String, typeof(System.String), null, null),
			new System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>("TotalDwellTime", ScopeRuntime.ColumnDataType.Double, typeof(System.Double), null, null),
		};

		ScopeRuntime.StringColumnData s0_Market;
		public ScopeRuntime.StringColumnData Market
		{
			get { return s0_Market; }
			set 
			{
				s0_Market = value;
				_columns[0] = value;
			}
		}
		ScopeRuntime.DoubleColumnData s0_TotalDwellTime;
		public ScopeRuntime.DoubleColumnData TotalDwellTime
		{
			get { return s0_TotalDwellTime; }
			set 
			{
				s0_TotalDwellTime = value;
				_columns[1] = value;
			}
		}
		public Row_Market_String_TotalDwellTime_Double(Schema schema, ColumnData[] columns) : base(schema, columns) { }
		public Row_Market_String_TotalDwellTime_Double(Schema schema) : base(schema)
		{
			for (int i = 0; i < _columns.Length; ++i)
			{
				this[i] = _columns[i];
			}
		}
		public Row_Market_String_TotalDwellTime_Double() : base(BuildSchema(), BuildColumnData())
		{
			for (int i = 0; i < _columns.Length; ++i)
			{
				this[i] = _columns[i];
			}
		}
		private static Schema BuildSchema()
		{
			Schema schema = new Schema();
			for (int i = 0; i < _columnTable.Length; ++i)
			{
				if (_columnTable[i].Item5 == null)
				{
					schema.Add(new ScopeRuntime.ColumnInfo(_columnTable[i].Item1, _columnTable[i].Item3));
				}
				else
				{
					schema.Add(new ScopeRuntime.ColumnInfo(_columnTable[i].Item1, _columnTable[i].Item5));
				}
			}
			return schema;
		}
		private static ColumnData[] BuildColumnData()
		{
			ColumnData[] columnData = new ColumnData[_columnTable.Length];
			for (int i = 0; i < _columnTable.Length; ++i)
			{
				if (_columnTable[i].Item5 == null)
				{
					columnData[i] = _columnTable[i].Item4 != null ? _columnTable[i].Item4() : ColumnDataFactory.Create(_columnTable[i].Item2);
				}
				else
				{
					columnData[i] = ColumnDataFactory.CreateStruct(_columnTable[i].Item5);
				}
			}
			return columnData;
		}
		public override ColumnData this[int index]
		{
			get { return _columns[index]; }
			set
			{
				_columns[index] = value;

				//  We also need to reset the property
				switch (index)
				{

					case 0:
					{
						s0_Market = (ScopeRuntime.StringColumnData)value;
						break;
					}
					case 1:
					{
						s0_TotalDwellTime = (ScopeRuntime.DoubleColumnData)value;
						break;
					}
				}
			}
		}
		public override void Serialize(BinaryWriter writer)
		{
			byte[] ___masking___ = new byte[1];
			___masking___[0] = 1;

			bool hasNull = false;
			if (s0_Market.IsNull())
			{
				hasNull = true;
				___masking___[0] |= (byte)(1 << 1);
			}
			if (hasNull)
			{
				writer.Write(___masking___[0]);
			}
			else
			{
				writer.Write( (byte) 0);
			}
			if (!s0_Market.IsNull())
			{
				s0_Market.Serialize(writer);
			}
			s0_TotalDwellTime.Serialize(writer);
		}

		public override void Deserialize(BinaryReader reader)
		{
			byte[] ___masking___ = new byte[1];
			byte firstByte = reader.ReadByte();
			if (firstByte == 0)
			{
				s0_Market.Deserialize(reader);
				s0_TotalDwellTime.Deserialize(reader);
			}
			else
			{
				___masking___[0] = firstByte;
				if ((___masking___[0] & 2) != 2)
				{
					s0_Market.Deserialize(reader);
				}
				else
				{
					s0_Market.SetNull();
				}
				s0_TotalDwellTime.Deserialize(reader);
			}
		}
	}


	public class ScopeGrouper_1 : Processor
	{
		//  Member variables used for aggregation
		byte[] Market;
		MySum_Double s0_TotalDwellTime_accum;
		public override IEnumerable<Row> Process(RowSet s0_input, Row s0_outRow, string[] s0_args)
		{
			//  Scope variables
			Row_Market_String_TotalDwellTime_Double s0_outputRow = (Row_Market_String_TotalDwellTime_Double)s0_outRow;
			IEnumerator<Row> s0_enumerator = s0_input.Rows.GetEnumerator();
			
			if (s0_enumerator.MoveNext())
			{
				bool s0_alldone = false;
				Row_Market_String_TotalDwellTime_Double s0_row = (Row_Market_String_TotalDwellTime_Double)s0_enumerator.Current;
				for (;;)
				{
					Market = s0_row.Market.Binary;
					s0_TotalDwellTime_accum = new MySum_Double();
					s0_TotalDwellTime_accum.Initialize();
					s0_TotalDwellTime_accum.Add(s0_row.TotalDwellTime.Double);
					for (;;)
					{
						s0_alldone = !s0_enumerator.MoveNext();
						if (s0_alldone) break;
						s0_row = (Row_Market_String_TotalDwellTime_Double)s0_enumerator.Current;
						if (ColumnDataComparer.Compare(Market, s0_row["Market"].Binary) != 0) 
							break;
						s0_TotalDwellTime_accum.Add(s0_row.TotalDwellTime.Double);
					}  // end of all rows with this key
					s0_outputRow.Market.Set(Market);
					s0_outputRow.TotalDwellTime.Set(s0_TotalDwellTime_accum.Finalize());
					yield return s0_outputRow;
					if (s0_alldone) break;
				}  // end of all keys
			}
		}
		public override void MemoryLoadNotification(uint loadPercent, ulong availableBytes)
		{
			if (s0_TotalDwellTime_accum != null) { s0_TotalDwellTime_accum.MemoryLoadNotification(loadPercent, availableBytes); }
		}
	}


	public class Row_7654143D4E1C7A3D : Row
	{
		private static readonly System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>[] _columnTable = 
		{
			new System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>("CLickedUrlsList", ScopeRuntime.ColumnDataType.UDT, typeof(___Scope_Generated_Classes___.UrlList), UDTExtensionWrapper.Create<___Scope_Generated_Classes____UrlList_ColumnData>, null),
			new System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>("IId", ScopeRuntime.ColumnDataType.Integer, typeof(System.Int32), null, null),
			new System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>("UId", ScopeRuntime.ColumnDataType.Integer, typeof(System.Int32), null, null),
			new System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>("Start", ScopeRuntime.ColumnDataType.DateTime, typeof(System.DateTime), null, null),
			new System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>("Market", ScopeRuntime.ColumnDataType.String, typeof(System.String), null, null),
			new System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>("Query", ScopeRuntime.ColumnDataType.String, typeof(System.String), null, null),
			new System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>("DwellTime", ScopeRuntime.ColumnDataType.Integer, typeof(System.Int32), null, null),
			new System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>("Results", ScopeRuntime.ColumnDataType.String, typeof(System.String), null, null),
		};

		___Scope_Generated_Classes____UrlList_ColumnData s0_CLickedUrlsList;
		public ___Scope_Generated_Classes____UrlList_ColumnData CLickedUrlsList
		{
			get { return s0_CLickedUrlsList; }
			set 
			{
				s0_CLickedUrlsList = value;
				_columns[0] = value;
			}
		}
		ScopeRuntime.IntegerColumnData s0_IId;
		public ScopeRuntime.IntegerColumnData IId
		{
			get { return s0_IId; }
			set 
			{
				s0_IId = value;
				_columns[1] = value;
			}
		}
		ScopeRuntime.IntegerColumnData s0_UId;
		public ScopeRuntime.IntegerColumnData UId
		{
			get { return s0_UId; }
			set 
			{
				s0_UId = value;
				_columns[2] = value;
			}
		}
		ScopeRuntime.DateTimeColumnData s0_Start;
		public ScopeRuntime.DateTimeColumnData Start
		{
			get { return s0_Start; }
			set 
			{
				s0_Start = value;
				_columns[3] = value;
			}
		}
		ScopeRuntime.StringColumnData s0_Market;
		public ScopeRuntime.StringColumnData Market
		{
			get { return s0_Market; }
			set 
			{
				s0_Market = value;
				_columns[4] = value;
			}
		}
		ScopeRuntime.StringColumnData s0_Query;
		public ScopeRuntime.StringColumnData Query
		{
			get { return s0_Query; }
			set 
			{
				s0_Query = value;
				_columns[5] = value;
			}
		}
		ScopeRuntime.IntegerColumnData s0_DwellTime;
		public ScopeRuntime.IntegerColumnData DwellTime
		{
			get { return s0_DwellTime; }
			set 
			{
				s0_DwellTime = value;
				_columns[6] = value;
			}
		}
		ScopeRuntime.StringColumnData s0_Results;
		public ScopeRuntime.StringColumnData Results
		{
			get { return s0_Results; }
			set 
			{
				s0_Results = value;
				_columns[7] = value;
			}
		}
		public Row_7654143D4E1C7A3D(Schema schema, ColumnData[] columns) : base(schema, columns) { }
		public Row_7654143D4E1C7A3D(Schema schema) : base(schema)
		{
			for (int i = 0; i < _columns.Length; ++i)
			{
				this[i] = _columns[i];
			}
		}
		public Row_7654143D4E1C7A3D() : base(BuildSchema(), BuildColumnData())
		{
			for (int i = 0; i < _columns.Length; ++i)
			{
				this[i] = _columns[i];
			}
		}
		private static Schema BuildSchema()
		{
			Schema schema = new Schema();
			for (int i = 0; i < _columnTable.Length; ++i)
			{
				if (_columnTable[i].Item5 == null)
				{
					schema.Add(new ScopeRuntime.ColumnInfo(_columnTable[i].Item1, _columnTable[i].Item3));
				}
				else
				{
					schema.Add(new ScopeRuntime.ColumnInfo(_columnTable[i].Item1, _columnTable[i].Item5));
				}
			}
			return schema;
		}
		private static ColumnData[] BuildColumnData()
		{
			ColumnData[] columnData = new ColumnData[_columnTable.Length];
			for (int i = 0; i < _columnTable.Length; ++i)
			{
				if (_columnTable[i].Item5 == null)
				{
					columnData[i] = _columnTable[i].Item4 != null ? _columnTable[i].Item4() : ColumnDataFactory.Create(_columnTable[i].Item2);
				}
				else
				{
					columnData[i] = ColumnDataFactory.CreateStruct(_columnTable[i].Item5);
				}
			}
			return columnData;
		}
		public override ColumnData this[int index]
		{
			get { return _columns[index]; }
			set
			{
				_columns[index] = value;

				//  We also need to reset the property
				switch (index)
				{

					case 0:
					{
						s0_CLickedUrlsList = (___Scope_Generated_Classes____UrlList_ColumnData)value;
						break;
					}
					case 1:
					{
						s0_IId = (ScopeRuntime.IntegerColumnData)value;
						break;
					}
					case 2:
					{
						s0_UId = (ScopeRuntime.IntegerColumnData)value;
						break;
					}
					case 3:
					{
						s0_Start = (ScopeRuntime.DateTimeColumnData)value;
						break;
					}
					case 4:
					{
						s0_Market = (ScopeRuntime.StringColumnData)value;
						break;
					}
					case 5:
					{
						s0_Query = (ScopeRuntime.StringColumnData)value;
						break;
					}
					case 6:
					{
						s0_DwellTime = (ScopeRuntime.IntegerColumnData)value;
						break;
					}
					case 7:
					{
						s0_Results = (ScopeRuntime.StringColumnData)value;
						break;
					}
				}
			}
		}
		public override void Serialize(BinaryWriter writer)
		{
			byte[] ___masking___ = new byte[1];
			___masking___[0] = 1;

			bool hasNull = false;
			if (s0_CLickedUrlsList.IsNull())
			{
				hasNull = true;
				___masking___[0] |= (byte)(1 << 1);
			}
			if (s0_Market.IsNull())
			{
				hasNull = true;
				___masking___[0] |= (byte)(1 << 2);
			}
			if (s0_Query.IsNull())
			{
				hasNull = true;
				___masking___[0] |= (byte)(1 << 3);
			}
			if (s0_Results.IsNull())
			{
				hasNull = true;
				___masking___[0] |= (byte)(1 << 4);
			}
			if (hasNull)
			{
				writer.Write(___masking___[0]);
			}
			else
			{
				writer.Write( (byte) 0);
			}
			if (!s0_CLickedUrlsList.IsNull())
			{
				s0_CLickedUrlsList.Serialize(writer);
			}
			s0_IId.Serialize(writer);
			s0_UId.Serialize(writer);
			s0_Start.Serialize(writer);
			if (!s0_Market.IsNull())
			{
				s0_Market.Serialize(writer);
			}
			if (!s0_Query.IsNull())
			{
				s0_Query.Serialize(writer);
			}
			s0_DwellTime.Serialize(writer);
			if (!s0_Results.IsNull())
			{
				s0_Results.Serialize(writer);
			}
		}

		public override void Deserialize(BinaryReader reader)
		{
			byte[] ___masking___ = new byte[1];
			byte firstByte = reader.ReadByte();
			if (firstByte == 0)
			{
				s0_CLickedUrlsList.Deserialize(reader);
				s0_IId.Deserialize(reader);
				s0_UId.Deserialize(reader);
				s0_Start.Deserialize(reader);
				s0_Market.Deserialize(reader);
				s0_Query.Deserialize(reader);
				s0_DwellTime.Deserialize(reader);
				s0_Results.Deserialize(reader);
			}
			else
			{
				___masking___[0] = firstByte;
				if ((___masking___[0] & 2) != 2)
				{
					s0_CLickedUrlsList.Deserialize(reader);
				}
				else
				{
					s0_CLickedUrlsList.SetNull();
				}
				s0_IId.Deserialize(reader);
				s0_UId.Deserialize(reader);
				s0_Start.Deserialize(reader);
				if ((___masking___[0] & 4) != 4)
				{
					s0_Market.Deserialize(reader);
				}
				else
				{
					s0_Market.SetNull();
				}
				if ((___masking___[0] & 8) != 8)
				{
					s0_Query.Deserialize(reader);
				}
				else
				{
					s0_Query.SetNull();
				}
				s0_DwellTime.Deserialize(reader);
				if ((___masking___[0] & 16) != 16)
				{
					s0_Results.Deserialize(reader);
				}
				else
				{
					s0_Results.SetNull();
				}
			}
		}
	}


	public class ScopeTransformer_9 : ScopeRuntime.Processor
	{
		public override IEnumerable<Row> Process(RowSet input, Row outputRow, string[] args)
		{
			Row_7654143D4E1C7A3D outRow = (Row_7654143D4E1C7A3D)outputRow;
			foreach (Row_2BFC241179AB532 row in input.Rows)
			{
				int exceptionIndex = 0;
				try
				{
					int col_IId = row.IId.Integer;
					int col_UId = row.UId.Integer;
					DateTime col_Start = row.Start.DateTime;
					StringColumnData col_Market = row.Market;
					StringColumnData col_Query = row.Query;
					int col_DwellTime = row.DwellTime.Integer;
					StringColumnData col_Results = row.Results;
					string col_ClickedUrls = row.ClickedUrls.String;

					outRow.CLickedUrlsList.Set((UrlList.Create(col_ClickedUrls)));
					exceptionIndex++;
					outRow.IId.Set((col_IId));
					exceptionIndex++;
					outRow.UId.Set((col_UId));
					exceptionIndex++;
					outRow.Start.Set((col_Start));
					exceptionIndex++;
					outRow.Market.Set((col_Market));
					exceptionIndex++;
					outRow.Query.Set((col_Query));
					exceptionIndex++;
					outRow.DwellTime.Set((col_DwellTime));
					exceptionIndex++;
					outRow.Results.Set((col_Results));
					exceptionIndex++;
				}
				catch (Exception exception)
				{
					ScopeEngineManaged.ExceptionHelper.WrapExpressionException(exceptionsInfo[exceptionIndex], row.Dump(), exception);
				}
				yield return outRow;
			} //end of foreach Row_2BFC241179AB532
		}
		public static string[] exceptionsInfo = 
		{
			@"UrlList.Create(ClickedUrls)",
			@"IId",
			@"UId",
			@"Start",
			@"Market",
			@"Query",
			@"DwellTime",
			@"Results",
		};
	}


	public class Row_B77608D6CD159476 : Row
	{
		private static readonly System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>[] _columnTable = 
		{
			new System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>("ClickedUrlsCount", ScopeRuntime.ColumnDataType.String, typeof(System.String), null, null),
			new System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>("IId", ScopeRuntime.ColumnDataType.Integer, typeof(System.Int32), null, null),
			new System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>("UId", ScopeRuntime.ColumnDataType.Integer, typeof(System.Int32), null, null),
			new System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>("Start", ScopeRuntime.ColumnDataType.DateTime, typeof(System.DateTime), null, null),
			new System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>("Market", ScopeRuntime.ColumnDataType.String, typeof(System.String), null, null),
			new System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>("Query", ScopeRuntime.ColumnDataType.String, typeof(System.String), null, null),
			new System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>("DwellTime", ScopeRuntime.ColumnDataType.Integer, typeof(System.Int32), null, null),
			new System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>("Results", ScopeRuntime.ColumnDataType.String, typeof(System.String), null, null),
		};

		ScopeRuntime.StringColumnData s0_ClickedUrlsCount;
		public ScopeRuntime.StringColumnData ClickedUrlsCount
		{
			get { return s0_ClickedUrlsCount; }
			set 
			{
				s0_ClickedUrlsCount = value;
				_columns[0] = value;
			}
		}
		ScopeRuntime.IntegerColumnData s0_IId;
		public ScopeRuntime.IntegerColumnData IId
		{
			get { return s0_IId; }
			set 
			{
				s0_IId = value;
				_columns[1] = value;
			}
		}
		ScopeRuntime.IntegerColumnData s0_UId;
		public ScopeRuntime.IntegerColumnData UId
		{
			get { return s0_UId; }
			set 
			{
				s0_UId = value;
				_columns[2] = value;
			}
		}
		ScopeRuntime.DateTimeColumnData s0_Start;
		public ScopeRuntime.DateTimeColumnData Start
		{
			get { return s0_Start; }
			set 
			{
				s0_Start = value;
				_columns[3] = value;
			}
		}
		ScopeRuntime.StringColumnData s0_Market;
		public ScopeRuntime.StringColumnData Market
		{
			get { return s0_Market; }
			set 
			{
				s0_Market = value;
				_columns[4] = value;
			}
		}
		ScopeRuntime.StringColumnData s0_Query;
		public ScopeRuntime.StringColumnData Query
		{
			get { return s0_Query; }
			set 
			{
				s0_Query = value;
				_columns[5] = value;
			}
		}
		ScopeRuntime.IntegerColumnData s0_DwellTime;
		public ScopeRuntime.IntegerColumnData DwellTime
		{
			get { return s0_DwellTime; }
			set 
			{
				s0_DwellTime = value;
				_columns[6] = value;
			}
		}
		ScopeRuntime.StringColumnData s0_Results;
		public ScopeRuntime.StringColumnData Results
		{
			get { return s0_Results; }
			set 
			{
				s0_Results = value;
				_columns[7] = value;
			}
		}
		public Row_B77608D6CD159476(Schema schema, ColumnData[] columns) : base(schema, columns) { }
		public Row_B77608D6CD159476(Schema schema) : base(schema)
		{
			for (int i = 0; i < _columns.Length; ++i)
			{
				this[i] = _columns[i];
			}
		}
		public Row_B77608D6CD159476() : base(BuildSchema(), BuildColumnData())
		{
			for (int i = 0; i < _columns.Length; ++i)
			{
				this[i] = _columns[i];
			}
		}
		private static Schema BuildSchema()
		{
			Schema schema = new Schema();
			for (int i = 0; i < _columnTable.Length; ++i)
			{
				if (_columnTable[i].Item5 == null)
				{
					schema.Add(new ScopeRuntime.ColumnInfo(_columnTable[i].Item1, _columnTable[i].Item3));
				}
				else
				{
					schema.Add(new ScopeRuntime.ColumnInfo(_columnTable[i].Item1, _columnTable[i].Item5));
				}
			}
			return schema;
		}
		private static ColumnData[] BuildColumnData()
		{
			ColumnData[] columnData = new ColumnData[_columnTable.Length];
			for (int i = 0; i < _columnTable.Length; ++i)
			{
				if (_columnTable[i].Item5 == null)
				{
					columnData[i] = _columnTable[i].Item4 != null ? _columnTable[i].Item4() : ColumnDataFactory.Create(_columnTable[i].Item2);
				}
				else
				{
					columnData[i] = ColumnDataFactory.CreateStruct(_columnTable[i].Item5);
				}
			}
			return columnData;
		}
		public override ColumnData this[int index]
		{
			get { return _columns[index]; }
			set
			{
				_columns[index] = value;

				//  We also need to reset the property
				switch (index)
				{

					case 0:
					{
						s0_ClickedUrlsCount = (ScopeRuntime.StringColumnData)value;
						break;
					}
					case 1:
					{
						s0_IId = (ScopeRuntime.IntegerColumnData)value;
						break;
					}
					case 2:
					{
						s0_UId = (ScopeRuntime.IntegerColumnData)value;
						break;
					}
					case 3:
					{
						s0_Start = (ScopeRuntime.DateTimeColumnData)value;
						break;
					}
					case 4:
					{
						s0_Market = (ScopeRuntime.StringColumnData)value;
						break;
					}
					case 5:
					{
						s0_Query = (ScopeRuntime.StringColumnData)value;
						break;
					}
					case 6:
					{
						s0_DwellTime = (ScopeRuntime.IntegerColumnData)value;
						break;
					}
					case 7:
					{
						s0_Results = (ScopeRuntime.StringColumnData)value;
						break;
					}
				}
			}
		}
		public override void Serialize(BinaryWriter writer)
		{
			byte[] ___masking___ = new byte[1];
			___masking___[0] = 1;

			bool hasNull = false;
			if (s0_ClickedUrlsCount.IsNull())
			{
				hasNull = true;
				___masking___[0] |= (byte)(1 << 1);
			}
			if (s0_Market.IsNull())
			{
				hasNull = true;
				___masking___[0] |= (byte)(1 << 2);
			}
			if (s0_Query.IsNull())
			{
				hasNull = true;
				___masking___[0] |= (byte)(1 << 3);
			}
			if (s0_Results.IsNull())
			{
				hasNull = true;
				___masking___[0] |= (byte)(1 << 4);
			}
			if (hasNull)
			{
				writer.Write(___masking___[0]);
			}
			else
			{
				writer.Write( (byte) 0);
			}
			if (!s0_ClickedUrlsCount.IsNull())
			{
				s0_ClickedUrlsCount.Serialize(writer);
			}
			s0_IId.Serialize(writer);
			s0_UId.Serialize(writer);
			s0_Start.Serialize(writer);
			if (!s0_Market.IsNull())
			{
				s0_Market.Serialize(writer);
			}
			if (!s0_Query.IsNull())
			{
				s0_Query.Serialize(writer);
			}
			s0_DwellTime.Serialize(writer);
			if (!s0_Results.IsNull())
			{
				s0_Results.Serialize(writer);
			}
		}

		public override void Deserialize(BinaryReader reader)
		{
			byte[] ___masking___ = new byte[1];
			byte firstByte = reader.ReadByte();
			if (firstByte == 0)
			{
				s0_ClickedUrlsCount.Deserialize(reader);
				s0_IId.Deserialize(reader);
				s0_UId.Deserialize(reader);
				s0_Start.Deserialize(reader);
				s0_Market.Deserialize(reader);
				s0_Query.Deserialize(reader);
				s0_DwellTime.Deserialize(reader);
				s0_Results.Deserialize(reader);
			}
			else
			{
				___masking___[0] = firstByte;
				if ((___masking___[0] & 2) != 2)
				{
					s0_ClickedUrlsCount.Deserialize(reader);
				}
				else
				{
					s0_ClickedUrlsCount.SetNull();
				}
				s0_IId.Deserialize(reader);
				s0_UId.Deserialize(reader);
				s0_Start.Deserialize(reader);
				if ((___masking___[0] & 4) != 4)
				{
					s0_Market.Deserialize(reader);
				}
				else
				{
					s0_Market.SetNull();
				}
				if ((___masking___[0] & 8) != 8)
				{
					s0_Query.Deserialize(reader);
				}
				else
				{
					s0_Query.SetNull();
				}
				s0_DwellTime.Deserialize(reader);
				if ((___masking___[0] & 16) != 16)
				{
					s0_Results.Deserialize(reader);
				}
				else
				{
					s0_Results.SetNull();
				}
			}
		}
	}


	public class ScopeTransformer_10 : ScopeRuntime.Processor
	{
		public override IEnumerable<Row> Process(RowSet input, Row outputRow, string[] args)
		{
			Row_B77608D6CD159476 outRow = (Row_B77608D6CD159476)outputRow;
			foreach (Row_7654143D4E1C7A3D row in input.Rows)
			{
				int exceptionIndex = 0;
				try
				{
					___Scope_Generated_Classes___.UrlList col_CLickedUrlsList = (___Scope_Generated_Classes___.UrlList)row.CLickedUrlsList.Value;
					int col_IId = row.IId.Integer;
					int col_UId = row.UId.Integer;
					DateTime col_Start = row.Start.DateTime;
					StringColumnData col_Market = row.Market;
					StringColumnData col_Query = row.Query;
					int col_DwellTime = row.DwellTime.Integer;
					StringColumnData col_Results = row.Results;

					outRow.ClickedUrlsCount.Set((col_CLickedUrlsList.Serialize()));
					exceptionIndex++;
					outRow.IId.Set((col_IId));
					exceptionIndex++;
					outRow.UId.Set((col_UId));
					exceptionIndex++;
					outRow.Start.Set((col_Start));
					exceptionIndex++;
					outRow.Market.Set((col_Market));
					exceptionIndex++;
					outRow.Query.Set((col_Query));
					exceptionIndex++;
					outRow.DwellTime.Set((col_DwellTime));
					exceptionIndex++;
					outRow.Results.Set((col_Results));
					exceptionIndex++;
				}
				catch (Exception exception)
				{
					ScopeEngineManaged.ExceptionHelper.WrapExpressionException(exceptionsInfo[exceptionIndex], row.Dump(), exception);
				}
				yield return outRow;
			} //end of foreach Row_7654143D4E1C7A3D
		}
		public static string[] exceptionsInfo = 
		{
			@"CLickedUrlsList.Serialize()",
			@"IId",
			@"UId",
			@"Start",
			@"Market",
			@"Query",
			@"DwellTime",
			@"Results",
		};
	}


	public class Row_2EDD8A91968976D1 : Row
	{
		private static readonly System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>[] _columnTable = 
		{
			new System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>("IId", ScopeRuntime.ColumnDataType.Integer, typeof(System.Int32), null, null),
			new System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>("UId", ScopeRuntime.ColumnDataType.Integer, typeof(System.Int32), null, null),
			new System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>("Start", ScopeRuntime.ColumnDataType.DateTime, typeof(System.DateTime), null, null),
			new System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>("Market", ScopeRuntime.ColumnDataType.String, typeof(System.String), null, null),
			new System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>("Query", ScopeRuntime.ColumnDataType.String, typeof(System.String), null, null),
			new System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>("DwellTime", ScopeRuntime.ColumnDataType.Integer, typeof(System.Int32), null, null),
			new System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>("Results", ScopeRuntime.ColumnDataType.String, typeof(System.String), null, null),
			new System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>("ClickedUrlsCount", ScopeRuntime.ColumnDataType.String, typeof(System.String), null, null),
		};

		ScopeRuntime.IntegerColumnData s0_IId;
		public ScopeRuntime.IntegerColumnData IId
		{
			get { return s0_IId; }
			set 
			{
				s0_IId = value;
				_columns[0] = value;
			}
		}
		ScopeRuntime.IntegerColumnData s0_UId;
		public ScopeRuntime.IntegerColumnData UId
		{
			get { return s0_UId; }
			set 
			{
				s0_UId = value;
				_columns[1] = value;
			}
		}
		ScopeRuntime.DateTimeColumnData s0_Start;
		public ScopeRuntime.DateTimeColumnData Start
		{
			get { return s0_Start; }
			set 
			{
				s0_Start = value;
				_columns[2] = value;
			}
		}
		ScopeRuntime.StringColumnData s0_Market;
		public ScopeRuntime.StringColumnData Market
		{
			get { return s0_Market; }
			set 
			{
				s0_Market = value;
				_columns[3] = value;
			}
		}
		ScopeRuntime.StringColumnData s0_Query;
		public ScopeRuntime.StringColumnData Query
		{
			get { return s0_Query; }
			set 
			{
				s0_Query = value;
				_columns[4] = value;
			}
		}
		ScopeRuntime.IntegerColumnData s0_DwellTime;
		public ScopeRuntime.IntegerColumnData DwellTime
		{
			get { return s0_DwellTime; }
			set 
			{
				s0_DwellTime = value;
				_columns[5] = value;
			}
		}
		ScopeRuntime.StringColumnData s0_Results;
		public ScopeRuntime.StringColumnData Results
		{
			get { return s0_Results; }
			set 
			{
				s0_Results = value;
				_columns[6] = value;
			}
		}
		ScopeRuntime.StringColumnData s0_ClickedUrlsCount;
		public ScopeRuntime.StringColumnData ClickedUrlsCount
		{
			get { return s0_ClickedUrlsCount; }
			set 
			{
				s0_ClickedUrlsCount = value;
				_columns[7] = value;
			}
		}
		public Row_2EDD8A91968976D1(Schema schema, ColumnData[] columns) : base(schema, columns) { }
		public Row_2EDD8A91968976D1(Schema schema) : base(schema)
		{
			for (int i = 0; i < _columns.Length; ++i)
			{
				this[i] = _columns[i];
			}
		}
		public Row_2EDD8A91968976D1() : base(BuildSchema(), BuildColumnData())
		{
			for (int i = 0; i < _columns.Length; ++i)
			{
				this[i] = _columns[i];
			}
		}
		private static Schema BuildSchema()
		{
			Schema schema = new Schema();
			for (int i = 0; i < _columnTable.Length; ++i)
			{
				if (_columnTable[i].Item5 == null)
				{
					schema.Add(new ScopeRuntime.ColumnInfo(_columnTable[i].Item1, _columnTable[i].Item3));
				}
				else
				{
					schema.Add(new ScopeRuntime.ColumnInfo(_columnTable[i].Item1, _columnTable[i].Item5));
				}
			}
			return schema;
		}
		private static ColumnData[] BuildColumnData()
		{
			ColumnData[] columnData = new ColumnData[_columnTable.Length];
			for (int i = 0; i < _columnTable.Length; ++i)
			{
				if (_columnTable[i].Item5 == null)
				{
					columnData[i] = _columnTable[i].Item4 != null ? _columnTable[i].Item4() : ColumnDataFactory.Create(_columnTable[i].Item2);
				}
				else
				{
					columnData[i] = ColumnDataFactory.CreateStruct(_columnTable[i].Item5);
				}
			}
			return columnData;
		}
		public override ColumnData this[int index]
		{
			get { return _columns[index]; }
			set
			{
				_columns[index] = value;

				//  We also need to reset the property
				switch (index)
				{

					case 0:
					{
						s0_IId = (ScopeRuntime.IntegerColumnData)value;
						break;
					}
					case 1:
					{
						s0_UId = (ScopeRuntime.IntegerColumnData)value;
						break;
					}
					case 2:
					{
						s0_Start = (ScopeRuntime.DateTimeColumnData)value;
						break;
					}
					case 3:
					{
						s0_Market = (ScopeRuntime.StringColumnData)value;
						break;
					}
					case 4:
					{
						s0_Query = (ScopeRuntime.StringColumnData)value;
						break;
					}
					case 5:
					{
						s0_DwellTime = (ScopeRuntime.IntegerColumnData)value;
						break;
					}
					case 6:
					{
						s0_Results = (ScopeRuntime.StringColumnData)value;
						break;
					}
					case 7:
					{
						s0_ClickedUrlsCount = (ScopeRuntime.StringColumnData)value;
						break;
					}
				}
			}
		}
		public override void Serialize(BinaryWriter writer)
		{
			byte[] ___masking___ = new byte[1];
			___masking___[0] = 1;

			bool hasNull = false;
			if (s0_Market.IsNull())
			{
				hasNull = true;
				___masking___[0] |= (byte)(1 << 1);
			}
			if (s0_Query.IsNull())
			{
				hasNull = true;
				___masking___[0] |= (byte)(1 << 2);
			}
			if (s0_Results.IsNull())
			{
				hasNull = true;
				___masking___[0] |= (byte)(1 << 3);
			}
			if (s0_ClickedUrlsCount.IsNull())
			{
				hasNull = true;
				___masking___[0] |= (byte)(1 << 4);
			}
			if (hasNull)
			{
				writer.Write(___masking___[0]);
			}
			else
			{
				writer.Write( (byte) 0);
			}
			s0_IId.Serialize(writer);
			s0_UId.Serialize(writer);
			s0_Start.Serialize(writer);
			if (!s0_Market.IsNull())
			{
				s0_Market.Serialize(writer);
			}
			if (!s0_Query.IsNull())
			{
				s0_Query.Serialize(writer);
			}
			s0_DwellTime.Serialize(writer);
			if (!s0_Results.IsNull())
			{
				s0_Results.Serialize(writer);
			}
			if (!s0_ClickedUrlsCount.IsNull())
			{
				s0_ClickedUrlsCount.Serialize(writer);
			}
		}

		public override void Deserialize(BinaryReader reader)
		{
			byte[] ___masking___ = new byte[1];
			byte firstByte = reader.ReadByte();
			if (firstByte == 0)
			{
				s0_IId.Deserialize(reader);
				s0_UId.Deserialize(reader);
				s0_Start.Deserialize(reader);
				s0_Market.Deserialize(reader);
				s0_Query.Deserialize(reader);
				s0_DwellTime.Deserialize(reader);
				s0_Results.Deserialize(reader);
				s0_ClickedUrlsCount.Deserialize(reader);
			}
			else
			{
				___masking___[0] = firstByte;
				s0_IId.Deserialize(reader);
				s0_UId.Deserialize(reader);
				s0_Start.Deserialize(reader);
				if ((___masking___[0] & 2) != 2)
				{
					s0_Market.Deserialize(reader);
				}
				else
				{
					s0_Market.SetNull();
				}
				if ((___masking___[0] & 4) != 4)
				{
					s0_Query.Deserialize(reader);
				}
				else
				{
					s0_Query.SetNull();
				}
				s0_DwellTime.Deserialize(reader);
				if ((___masking___[0] & 8) != 8)
				{
					s0_Results.Deserialize(reader);
				}
				else
				{
					s0_Results.SetNull();
				}
				if ((___masking___[0] & 16) != 16)
				{
					s0_ClickedUrlsCount.Deserialize(reader);
				}
				else
				{
					s0_ClickedUrlsCount.SetNull();
				}
			}
		}
	}


	public class ScopeSplitOutputter_3 : BinarySplitOutputter<Row_Query_String_IId1_Integer>
	{
		Row_Query_String_IId1_Integer m_outRow = new Row_Query_String_IId1_Integer();
		public override void Process(Row inputRow)
		{
			if(EvaluateTransform(inputRow, m_outRow))
			{
				Output(m_outRow);
			}
		}
		public bool EvaluateTransform(Row inputRow, Row outputRow)
		{
			Row_2BFC241179AB532 row = (Row_2BFC241179AB532)inputRow;
			Row_Query_String_IId1_Integer outRow = (Row_Query_String_IId1_Integer)outputRow;
			int col_IId = row.IId.Integer;
			int col_UId = row.UId.Integer;
			DateTime col_Start = row.Start.DateTime;
			StringColumnData col_Market = row.Market;
			StringColumnData col_Query = row.Query;
			int col_DwellTime = row.DwellTime.Integer;
			StringColumnData col_Results = row.Results;
			StringColumnData col_ClickedUrls = row.ClickedUrls;
			bool bPicked = false;
			int exceptionIndex = 0;
			try
			{
				{
					bPicked = true;
					outRow.Query.Set((col_Query));
					exceptionIndex++;
					outRow.IId1.Set((col_IId));
					exceptionIndex++;
				}
			}
			catch (Exception exception)
			{
				ScopeEngineManaged.ExceptionHelper.WrapExpressionException(exceptionsInfo[exceptionIndex], row.Dump(), exception);
			}
			return bPicked;
		}
		public static string[] exceptionsInfo = 
		{
			@"Query",
			@"IId",
		};
	}


	public class ScopeSplitOutputter_4 : DefaultTextSplitOutputter<Row_2BFC241179AB532>
	{
		Row_2BFC241179AB532 m_outRow = new Row_2BFC241179AB532();
		public override void Process(Row inputRow)
		{
			if(EvaluateTransform(inputRow, m_outRow))
			{
				Output(m_outRow);
			}
		}
		public bool EvaluateTransform(Row inputRow, Row outputRow)
		{
			Row_2BFC241179AB532 row = (Row_2BFC241179AB532)inputRow;
			Row_2BFC241179AB532 outRow = (Row_2BFC241179AB532)outputRow;
			int col_IId = row.IId.Integer;
			int col_UId = row.UId.Integer;
			DateTime col_Start = row.Start.DateTime;
			StringColumnData col_Market = row.Market;
			StringColumnData col_Query = row.Query;
			int col_DwellTime = row.DwellTime.Integer;
			StringColumnData col_Results = row.Results;
			StringColumnData col_ClickedUrls = row.ClickedUrls;
			bool bPicked = false;
			int exceptionIndex = 0;
			try
			{
				{
					bPicked = true;
					outRow.IId.Set((col_IId));
					exceptionIndex++;
					outRow.UId.Set((col_UId));
					exceptionIndex++;
					outRow.Start.Set((col_Start));
					exceptionIndex++;
					outRow.Market.Set((col_Market));
					exceptionIndex++;
					outRow.Query.Set((col_Query));
					exceptionIndex++;
					outRow.DwellTime.Set((col_DwellTime));
					exceptionIndex++;
					outRow.Results.Set((col_Results));
					exceptionIndex++;
					outRow.ClickedUrls.Set((col_ClickedUrls));
					exceptionIndex++;
				}
			}
			catch (Exception exception)
			{
				ScopeEngineManaged.ExceptionHelper.WrapExpressionException(exceptionsInfo[exceptionIndex], row.Dump(), exception);
			}
			return bPicked;
		}
		public static string[] exceptionsInfo = 
		{
			@"IId",
			@"UId",
			@"Start",
			@"Market",
			@"Query",
			@"DwellTime",
			@"Results",
			@"ClickedUrls",
		};
	}


	public class ScopeSplitOutputter_5 : BinarySplitOutputter<Row_Market_String_Results_String>
	{
		Row_Market_String_Results_String m_outRow = new Row_Market_String_Results_String();
		public override void Process(Row inputRow)
		{
			if(EvaluateTransform(inputRow, m_outRow))
			{
				Output(m_outRow);
			}
		}
		public bool EvaluateTransform(Row inputRow, Row outputRow)
		{
			Row_2BFC241179AB532 row = (Row_2BFC241179AB532)inputRow;
			Row_Market_String_Results_String outRow = (Row_Market_String_Results_String)outputRow;
			int col_IId = row.IId.Integer;
			int col_UId = row.UId.Integer;
			DateTime col_Start = row.Start.DateTime;
			StringColumnData col_Market = row.Market;
			StringColumnData col_Query = row.Query;
			int col_DwellTime = row.DwellTime.Integer;
			StringColumnData col_Results = row.Results;
			StringColumnData col_ClickedUrls = row.ClickedUrls;
			bool bPicked = false;
			int exceptionIndex = 0;
			try
			{
				{
					bPicked = true;
					outRow.Market.Set((col_Market));
					exceptionIndex++;
					outRow.Results.Set((col_Results));
					exceptionIndex++;
				}
			}
			catch (Exception exception)
			{
				ScopeEngineManaged.ExceptionHelper.WrapExpressionException(exceptionsInfo[exceptionIndex], row.Dump(), exception);
			}
			return bPicked;
		}
		public static string[] exceptionsInfo = 
		{
			@"Market",
			@"Results",
		};
	}


	public class ScopeSplitOutputter_6 : BinarySplitOutputter<Row_Market_String_DwellTimeDouble_Double>
	{
		Row_Market_String_DwellTimeDouble_Double m_outRow = new Row_Market_String_DwellTimeDouble_Double();
		public override void Process(Row inputRow)
		{
			if(EvaluateTransform(inputRow, m_outRow))
			{
				Output(m_outRow);
			}
		}
		public bool EvaluateTransform(Row inputRow, Row outputRow)
		{
			Row_2BFC241179AB532 row = (Row_2BFC241179AB532)inputRow;
			Row_Market_String_DwellTimeDouble_Double outRow = (Row_Market_String_DwellTimeDouble_Double)outputRow;
			int col_IId = row.IId.Integer;
			int col_UId = row.UId.Integer;
			DateTime col_Start = row.Start.DateTime;
			StringColumnData col_Market = row.Market;
			StringColumnData col_Query = row.Query;
			int col_DwellTime = row.DwellTime.Integer;
			StringColumnData col_Results = row.Results;
			StringColumnData col_ClickedUrls = row.ClickedUrls;
			bool bPicked = false;
			int exceptionIndex = 0;
			try
			{
				{
					bPicked = true;
					outRow.Market.Set((col_Market));
					exceptionIndex++;
					outRow.DwellTimeDouble.Set(((double)col_DwellTime));
					exceptionIndex++;
				}
			}
			catch (Exception exception)
			{
				ScopeEngineManaged.ExceptionHelper.WrapExpressionException(exceptionsInfo[exceptionIndex], row.Dump(), exception);
			}
			return bPicked;
		}
		public static string[] exceptionsInfo = 
		{
			@"Market",
			@"(double)DwellTime",
		};
	}


	public class ScopeSplitOutputter_7 : DefaultTextSplitOutputter<Row_2EDD8A91968976D1>
	{
		Row_2EDD8A91968976D1 m_outRow = new Row_2EDD8A91968976D1();
		public override void Process(Row inputRow)
		{
			if(EvaluateTransform(inputRow, m_outRow))
			{
				Output(m_outRow);
			}
		}
		public bool EvaluateTransform(Row inputRow, Row outputRow)
		{
			Row_2BFC241179AB532 row = (Row_2BFC241179AB532)inputRow;
			Row_2EDD8A91968976D1 outRow = (Row_2EDD8A91968976D1)outputRow;
			int col_IId = row.IId.Integer;
			int col_UId = row.UId.Integer;
			DateTime col_Start = row.Start.DateTime;
			StringColumnData col_Market = row.Market;
			StringColumnData col_Query = row.Query;
			int col_DwellTime = row.DwellTime.Integer;
			StringColumnData col_Results = row.Results;
			string col_ClickedUrls = row.ClickedUrls.String;
			bool bPicked = false;
			int exceptionIndex = 0;
			try
			{
				{
					bPicked = true;
					outRow.IId.Set((col_IId));
					exceptionIndex++;
					outRow.UId.Set((col_UId));
					exceptionIndex++;
					outRow.Start.Set((col_Start));
					exceptionIndex++;
					outRow.Market.Set((col_Market));
					exceptionIndex++;
					outRow.Query.Set((col_Query));
					exceptionIndex++;
					outRow.DwellTime.Set((col_DwellTime));
					exceptionIndex++;
					outRow.Results.Set((col_Results));
					exceptionIndex++;
					outRow.ClickedUrlsCount.Set((UrlList.Create(col_ClickedUrls).Serialize()));
					exceptionIndex++;
				}
			}
			catch (Exception exception)
			{
				ScopeEngineManaged.ExceptionHelper.WrapExpressionException(exceptionsInfo[exceptionIndex], row.Dump(), exception);
			}
			return bPicked;
		}
		public static string[] exceptionsInfo = 
		{
			@"IId",
			@"UId",
			@"Start",
			@"Market",
			@"Query",
			@"DwellTime",
			@"Results",
			@"UrlList.Create(ClickedUrls).Serialize()",
		};
	}


	public class ___Scope_Generated_Classes____UrlList_ColumnData : UserDefinedTypeColumnData<___Scope_Generated_Classes___.UrlList>
	{
		public ___Scope_Generated_Classes____UrlList_ColumnData() {}
		public ___Scope_Generated_Classes____UrlList_ColumnData(___Scope_Generated_Classes___.UrlList v) : base(v) {}
		public static readonly string typeInSchema = "___Scope_Generated_Classes___.UrlList";
		public override void Serialize(System.IO.BinaryWriter writer)
		{
			var udtFormatter = new BinaryValueWriter(writer, false);
			UDTExtensionWrapper.Write(udtFormatter, _value);
		}
		public override void Deserialize(System.IO.BinaryReader reader)
		{
			var udtFormatter = new BinaryValueReader(reader, false);
			UDTExtensionWrapper.Read(udtFormatter, out _value);
		}
		public override ColumnData Clone()
		{
			___Scope_Generated_Classes____UrlList_ColumnData udt = new ___Scope_Generated_Classes____UrlList_ColumnData();
			var seenObject = new ReferenceHashTable<object>(false);
			udt._value = (IsNull()) ? null : _value.ScopeClone(seenObject);
			return udt;
		}
		public override void SetNull()
		{
			_value = null;
		}
		public override bool IsNull()
		{
			return (_value == null);
		}
	}


	public static System.Type[] __UdtTypeTable__ =
	{
		typeof(___Scope_Generated_Classes____UrlList_ColumnData)
	};

	public static class __OperatorFactory__
	{
		public static ScopeRuntime.Extractor Create_Extract_0()
		{
			return new   MyTSVExtractor();
		}
		public static string Name_Extract_0 = "___Scope_Generated_Classes___.MyTSVExtractor";
		public static ScopeRuntime.Processor Create_Process_10()
		{
			return new ___Scope_Generated_Classes___.ScopeCrossApplyProcessor_1();
		}
		public static string Name_Process_10 = "___Scope_Generated_Classes___.ScopeCrossApplyProcessor_1";
		public static ScopeRuntime.Processor Create_Process_15()
		{
			return new ___Scope_Generated_Classes___.ScopeGrouper_1();
		}
		public static string Name_Process_15 = "___Scope_Generated_Classes___.ScopeGrouper_1";
	}
}

	static public class UDTExtensionWrapper
	{
		static public void Write(BinaryValueWriter writer, System.Collections.Generic.List<System.String> value)
		{
			if (writer.WriteFlags(value)) { return; }
			writer.Write(value.Count);
			foreach (System.String elem in value) { writer.Write(elem); }
		}
		static public void Read(BinaryValueReader reader, out System.Collections.Generic.List<System.String> value)
		{
		    object o = reader.ReadFlags();
		    if (o != reader.NonExistentObject)
		    {
		        value = o as System.Collections.Generic.List<System.String>;
		        return;
		    }

		    long objectOffset = reader.Offset;
		    int count;
		    reader.Read(out count);
		    value = new System.Collections.Generic.List<System.String>(count);
		    reader.AddObjectOffset(value, objectOffset);
		    for (int i = 0; i < count; i++)
		    {
		        System.String item;
		        reader.Read(out item);
		        value.Add(item);
		    }

		}

		static public System.Collections.Generic.List<System.String> ScopeClone(this System.Collections.Generic.List<System.String> source, ReferenceHashTable<object> seenObject)
		{
		    if (seenObject.TryGetValue(source))
		    {
		        return seenObject.LastSearchValue as System.Collections.Generic.List<System.String>;
		    }

		    System.Collections.Generic.List<System.String> result = new System.Collections.Generic.List<System.String>(source.Count);
		    seenObject.Add(source, result, seenObject.LastKeyHash);
		    foreach (System.String elem in source)
		    {
		        result.Add(elem);
		    }

		    return result;
		}


		static public void Write(BinaryValueWriter writer, ___Scope_Generated_Classes___.UrlList value)
		{
			if (writer.WriteFlags(value)) { return; }
			UDTExtensionWrapper.Write(writer, value.Items);
		}
		static public void Read(BinaryValueReader reader, out ___Scope_Generated_Classes___.UrlList value)
		{
			object o = reader.ReadFlags();
			if (o != reader.NonExistentObject) { value = o as ___Scope_Generated_Classes___.UrlList; return; }
			value = (___Scope_Generated_Classes___.UrlList)FormatterServices.GetUninitializedObject(typeof(___Scope_Generated_Classes___.UrlList));
			reader.AddObjectOffset(value, reader.Offset);
			UDTExtensionWrapper.Read(reader, out value.Items);
		}
		static public ___Scope_Generated_Classes___.UrlList ScopeClone(this ___Scope_Generated_Classes___.UrlList source, ReferenceHashTable<object> seenObject)
		{
			if (seenObject.TryGetValue(source)) { return seenObject.LastSearchValue as ___Scope_Generated_Classes___.UrlList; }
			___Scope_Generated_Classes___.UrlList result = (___Scope_Generated_Classes___.UrlList)FormatterServices.GetUninitializedObject(typeof(___Scope_Generated_Classes___.UrlList));
			seenObject.Add(source, result, seenObject.LastKeyHash);
			if (source.Items == null) { result.Items = null; }
			else
			{
				result.Items = source.Items.ScopeClone(seenObject);
			}
			return result;
		}

                public static T Create<T>() where T : new() 
                { 
                    return new T(); 
                }

                private static readonly System.Collections.Generic.Dictionary<System.Collections.Generic.IEqualityComparer<string>, byte> StringComparerToByteMap =
                    new System.Collections.Generic.Dictionary<System.Collections.Generic.IEqualityComparer<string>, byte>()
                    {
                        {System.Collections.Generic.EqualityComparer<string>.Default, 0},
                        {System.StringComparer.CurrentCulture, 1},
                        {System.StringComparer.CurrentCultureIgnoreCase, 2},
                        {System.StringComparer.InvariantCulture, 3},
                        {System.StringComparer.InvariantCultureIgnoreCase, 4},
                        {System.StringComparer.Ordinal, 5},
                        {System.StringComparer.OrdinalIgnoreCase, 6},
                    };

                private static readonly System.Collections.Generic.Dictionary<byte, System.Collections.Generic.IEqualityComparer<string>> ByteToStringComparerMap =
                    System.Linq.Enumerable.ToDictionary(StringComparerToByteMap, kvp => kvp.Value, kvp => kvp.Key);

                public static void Read(BinaryValueReader reader, out System.StringComparer value)
                {
                    byte comparerKey;
                    reader.Read(out comparerKey);
                    value = ByteToStringComparerMap[comparerKey] as System.StringComparer;
                }

                public static void Write(BinaryValueWriter writer, System.StringComparer value)
                {
                    // If System.StringComparer is not one of the 6 we recognize, comparerKey should be 0.
                    byte comparerKey;
                    StringComparerToByteMap.TryGetValue(value as System.Collections.Generic.IEqualityComparer<string> ?? System.Collections.Generic.EqualityComparer<string>.Default, out comparerKey);
                    writer.Write(comparerKey);
                }

                static public ScopeStruct       ScopeClone(this ScopeStruct value, ReferenceHashTable<object> seenObject)
                {
                    return (ScopeStruct)new StructColumnData(value).Clone().Value;
                }

                static public ScopeMap<K,V>     ScopeClone<K,V>(this ScopeMap<K,V> value, ReferenceHashTable<object> seenObject)
                {
                    return (ScopeMap<K,V>)new MapColumnData<K,V>(value).Clone().Value;
                }

                static public ScopeArray<T>     ScopeClone<T>(this ScopeArray<T> value, ReferenceHashTable<object> seenObject)
                {
                    return (ScopeArray<T>)new ArrayColumnData<T>(value).Clone().Value;
                }

                static public void Write<T>(BinaryValueWriter writer, ScopeArray<T> v)
                {
                    writer.Write(v);
                }

                static public void Read<T>(BinaryValueReader reader, out ScopeArray<T> v)
                {
                    reader.Read(out v);
                } 

                static public void Write<K,V>(BinaryValueWriter writer, ScopeMap<K,V> v)
                {
                    writer.Write(v);
                }

                static public void Read<K,V>(BinaryValueReader reader, out ScopeMap<K,V> v)
                {
                    reader.Read(out v);
                }                 
                

	}