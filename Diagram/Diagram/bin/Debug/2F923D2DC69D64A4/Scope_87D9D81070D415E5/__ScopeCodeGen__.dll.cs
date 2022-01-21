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

#endregion ==END USER CODE==

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


	public class Row_IId_Integer_Market_String_Query_String_DwellTime_Integer : Row
	{
		private static readonly System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>[] _columnTable = 
		{
			new System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>("IId", ScopeRuntime.ColumnDataType.Integer, typeof(System.Int32), null, null),
			new System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>("Market", ScopeRuntime.ColumnDataType.String, typeof(System.String), null, null),
			new System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>("Query", ScopeRuntime.ColumnDataType.String, typeof(System.String), null, null),
			new System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>("DwellTime", ScopeRuntime.ColumnDataType.Integer, typeof(System.Int32), null, null),
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
		ScopeRuntime.StringColumnData s0_Query;
		public ScopeRuntime.StringColumnData Query
		{
			get { return s0_Query; }
			set 
			{
				s0_Query = value;
				_columns[2] = value;
			}
		}
		ScopeRuntime.IntegerColumnData s0_DwellTime;
		public ScopeRuntime.IntegerColumnData DwellTime
		{
			get { return s0_DwellTime; }
			set 
			{
				s0_DwellTime = value;
				_columns[3] = value;
			}
		}
		public Row_IId_Integer_Market_String_Query_String_DwellTime_Integer(Schema schema, ColumnData[] columns) : base(schema, columns) { }
		public Row_IId_Integer_Market_String_Query_String_DwellTime_Integer(Schema schema) : base(schema)
		{
			for (int i = 0; i < _columns.Length; ++i)
			{
				this[i] = _columns[i];
			}
		}
		public Row_IId_Integer_Market_String_Query_String_DwellTime_Integer() : base(BuildSchema(), BuildColumnData())
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
						s0_Market = (ScopeRuntime.StringColumnData)value;
						break;
					}
					case 2:
					{
						s0_Query = (ScopeRuntime.StringColumnData)value;
						break;
					}
					case 3:
					{
						s0_DwellTime = (ScopeRuntime.IntegerColumnData)value;
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
			if (hasNull)
			{
				writer.Write(___masking___[0]);
			}
			else
			{
				writer.Write( (byte) 0);
			}
			s0_IId.Serialize(writer);
			if (!s0_Market.IsNull())
			{
				s0_Market.Serialize(writer);
			}
			if (!s0_Query.IsNull())
			{
				s0_Query.Serialize(writer);
			}
			s0_DwellTime.Serialize(writer);
		}

		public override void Deserialize(BinaryReader reader)
		{
			byte[] ___masking___ = new byte[1];
			byte firstByte = reader.ReadByte();
			if (firstByte == 0)
			{
				s0_IId.Deserialize(reader);
				s0_Market.Deserialize(reader);
				s0_Query.Deserialize(reader);
				s0_DwellTime.Deserialize(reader);
			}
			else
			{
				___masking___[0] = firstByte;
				s0_IId.Deserialize(reader);
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
			}
		}
	}


	public class Row_IId_Integer_Query_String_DwellTime_Integer : Row
	{
		private static readonly System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>[] _columnTable = 
		{
			new System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>("IId", ScopeRuntime.ColumnDataType.Integer, typeof(System.Int32), null, null),
			new System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>("Query", ScopeRuntime.ColumnDataType.String, typeof(System.String), null, null),
			new System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>("DwellTime", ScopeRuntime.ColumnDataType.Integer, typeof(System.Int32), null, null),
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
		ScopeRuntime.StringColumnData s0_Query;
		public ScopeRuntime.StringColumnData Query
		{
			get { return s0_Query; }
			set 
			{
				s0_Query = value;
				_columns[1] = value;
			}
		}
		ScopeRuntime.IntegerColumnData s0_DwellTime;
		public ScopeRuntime.IntegerColumnData DwellTime
		{
			get { return s0_DwellTime; }
			set 
			{
				s0_DwellTime = value;
				_columns[2] = value;
			}
		}
		public Row_IId_Integer_Query_String_DwellTime_Integer(Schema schema, ColumnData[] columns) : base(schema, columns) { }
		public Row_IId_Integer_Query_String_DwellTime_Integer(Schema schema) : base(schema)
		{
			for (int i = 0; i < _columns.Length; ++i)
			{
				this[i] = _columns[i];
			}
		}
		public Row_IId_Integer_Query_String_DwellTime_Integer() : base(BuildSchema(), BuildColumnData())
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
						s0_Query = (ScopeRuntime.StringColumnData)value;
						break;
					}
					case 2:
					{
						s0_DwellTime = (ScopeRuntime.IntegerColumnData)value;
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
			s0_IId.Serialize(writer);
			if (!s0_Query.IsNull())
			{
				s0_Query.Serialize(writer);
			}
			s0_DwellTime.Serialize(writer);
		}

		public override void Deserialize(BinaryReader reader)
		{
			byte[] ___masking___ = new byte[1];
			byte firstByte = reader.ReadByte();
			if (firstByte == 0)
			{
				s0_IId.Deserialize(reader);
				s0_Query.Deserialize(reader);
				s0_DwellTime.Deserialize(reader);
			}
			else
			{
				___masking___[0] = firstByte;
				s0_IId.Deserialize(reader);
				if ((___masking___[0] & 2) != 2)
				{
					s0_Query.Deserialize(reader);
				}
				else
				{
					s0_Query.SetNull();
				}
				s0_DwellTime.Deserialize(reader);
			}
		}
	}


	public class Row_Query_String_DwellTime_Integer_IId1_Integer : Row
	{
		private static readonly System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>[] _columnTable = 
		{
			new System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>("Query", ScopeRuntime.ColumnDataType.String, typeof(System.String), null, null),
			new System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>("DwellTime", ScopeRuntime.ColumnDataType.Integer, typeof(System.Int32), null, null),
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
		ScopeRuntime.IntegerColumnData s0_IId1;
		public ScopeRuntime.IntegerColumnData IId1
		{
			get { return s0_IId1; }
			set 
			{
				s0_IId1 = value;
				_columns[2] = value;
			}
		}
		public Row_Query_String_DwellTime_Integer_IId1_Integer(Schema schema, ColumnData[] columns) : base(schema, columns) { }
		public Row_Query_String_DwellTime_Integer_IId1_Integer(Schema schema) : base(schema)
		{
			for (int i = 0; i < _columns.Length; ++i)
			{
				this[i] = _columns[i];
			}
		}
		public Row_Query_String_DwellTime_Integer_IId1_Integer() : base(BuildSchema(), BuildColumnData())
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
						s0_DwellTime = (ScopeRuntime.IntegerColumnData)value;
						break;
					}
					case 2:
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
			s0_DwellTime.Serialize(writer);
			s0_IId1.Serialize(writer);
		}

		public override void Deserialize(BinaryReader reader)
		{
			byte[] ___masking___ = new byte[1];
			byte firstByte = reader.ReadByte();
			if (firstByte == 0)
			{
				s0_Query.Deserialize(reader);
				s0_DwellTime.Deserialize(reader);
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
				s0_DwellTime.Deserialize(reader);
				s0_IId1.Deserialize(reader);
			}
		}
	}


	public class Row_AdId_Integer_IId_Integer_Impression_Integer_Query_String_DwellTime_Integer : Row
	{
		private static readonly System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>[] _columnTable = 
		{
			new System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>("AdId", ScopeRuntime.ColumnDataType.Integer, typeof(System.Int32), null, null),
			new System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>("IId", ScopeRuntime.ColumnDataType.Integer, typeof(System.Int32), null, null),
			new System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>("Impression", ScopeRuntime.ColumnDataType.Integer, typeof(System.Int32), null, null),
			new System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>("Query", ScopeRuntime.ColumnDataType.String, typeof(System.String), null, null),
			new System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>("DwellTime", ScopeRuntime.ColumnDataType.Integer, typeof(System.Int32), null, null),
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
		ScopeRuntime.IntegerColumnData s0_DwellTime;
		public ScopeRuntime.IntegerColumnData DwellTime
		{
			get { return s0_DwellTime; }
			set 
			{
				s0_DwellTime = value;
				_columns[4] = value;
			}
		}
		public Row_AdId_Integer_IId_Integer_Impression_Integer_Query_String_DwellTime_Integer(Schema schema, ColumnData[] columns) : base(schema, columns) { }
		public Row_AdId_Integer_IId_Integer_Impression_Integer_Query_String_DwellTime_Integer(Schema schema) : base(schema)
		{
			for (int i = 0; i < _columns.Length; ++i)
			{
				this[i] = _columns[i];
			}
		}
		public Row_AdId_Integer_IId_Integer_Impression_Integer_Query_String_DwellTime_Integer() : base(BuildSchema(), BuildColumnData())
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
					case 4:
					{
						s0_DwellTime = (ScopeRuntime.IntegerColumnData)value;
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
			s0_DwellTime.Serialize(writer);
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
				s0_DwellTime.Deserialize(reader);
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
				s0_DwellTime.Deserialize(reader);
			}
		}
	}


	public static System.Type[] __UdtTypeTable__ =
	{
		
	};

	public static class __OperatorFactory__
	{
		public static ScopeRuntime.Processor Create_Process_8()
		{
			return new  ImpressionProcessor();
		}
		public static string Name_Process_8 = "___Scope_Generated_Classes___.ImpressionProcessor";
	}
}

	static public class UDTExtensionWrapper
	{
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