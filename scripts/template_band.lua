ardour {
	["type"]    = "EditorAction",
	name        = "Track Wizard",
	description = [[
This template helps create the tracks for a typical pop/rock band.

You will be prompted to assemble your session from a list of track types.

Each track will be pre-assigned with a color.

Optionally, tracks may be assigned to sensible Groups ( vocals, guitars, drums )

Optionally, tracks may be assigned Gates and other plugins.
]]
}

function session_setup ()
	return true
end

function route_setup ()
	return
	{
		['Insert_at'] = ARDOUR.PresentationInfo.max_order
	}
end

function factory (params) return function ()

	local p         = params or route_setup ()
	local insert_at = p["insert_at"] or ARDOUR.PresentationInfo.max_order

	--prompt the user for the tracks they'd like to instantiate
	local dialog_options = {
		{ type = "heading", title = "Select the tracks you'd like\nto add to your session: ", col=0, align = "left", colspan = 1},
		{ type = "heading", title = "Name", col=1, colspan = 1 },
		{ type = "heading", title = "Stereo?", col=2, colspan = 1 },

		{ type = "checkbox", key = "check-ldvox",  default = false,        title = "Lead Vocal", col=0 },
		{ type = "entry",    key = "name-ldvox",   default = "Lead Vocal", title = "", col=1 },
		{ type = "checkbox", key = "stereo-ldvox", default = false,        title = "", col=2 },

		{ type = "checkbox", key = "check-bass", default = false, title = "Bass", col=0 },
		{ type = "entry",    key = "name-bass",   default = "Bass", title = "", col=1 },
		{ type = "checkbox", key = "stereo-bass", default = false,        title = "", col=2 },

		{ type = "checkbox", key = "check-piano", default = false, title = "Piano", col=0 },
		{ type = "entry",    key = "name-piano",   default = "Piano", title = "", col=1 },
		{ type = "checkbox", key = "stereo-piano", default = false,        title = "", col=2 },

		{ type = "checkbox", key = "check-electric-piano", default = false, title = "Electric Piano", col=0 },
		{ type = "entry",    key = "name-electric-piano",   default = "E Piano", title = "", col=1 },
		{ type = "checkbox", key = "stereo-electric-piano", default = false,        title = "", col=2 },

		{ type = "checkbox", key = "check-organ", default = false, title = "Organ", col=0 },
		{ type = "entry",    key = "name-organ",   default = "Organ", title = "", col=1 },
		{ type = "checkbox", key = "stereo-organ", default = false,        title = "", col=2 },

		{ type = "checkbox", key = "check-electric-guitar", default = false, title = "Electric Guitar", col=0 },
		{ type = "entry",    key = "name-electric-guitar",   default = "E Guitar", title = "", col=1 },
		{ type = "checkbox", key = "stereo-electric-guitar", default = false,        title = "", col=2 },

		{ type = "checkbox", key = "check-solo-guitar", default = false, title = "Lead Guitar", col=0 },
		{ type = "entry",    key = "name-solo-guitar",   default = "Ld Gtr", title = "", col=1 },
		{ type = "checkbox", key = "stereo-solo-guitar", default = false,        title = "", col=2 },

		{ type = "checkbox", key = "check-accoustic-guitar", default = false, title = "Acoustic Guitar", col=0 },
		{ type = "entry",    key = "name-accoustic-guitar",   default = "Ac Gtr", title = "", col=1 },
		{ type = "checkbox", key = "stereo-accoustic-guitar", default = false,        title = "", col=2 },

		{ type = "checkbox", key = "check-basic-kit", default = false, title = "Basic Drum Mics", col=0 },
		{ type = "label",  title = "(Kick + Snare)", col=1, colspan = 1, align = "left"},
--		{ type = "checkbox", key = "stereo-overhead-mono", default = false,        title = "", col=2 },

		{ type = "checkbox", key = "check-full-kit", default = false, title = "Full Drum Mics", col=0 },
		{ type = "label",  title = "(Kick, Snare, HiHat, 3 Toms)", col=1, colspan = 1, align = "left"},
--		{ type = "checkbox", key = "stereo-overhead-mono", default = false,        title = "", col=2 },

		{ type = "checkbox", key = "check-overkill-kit", default = false, title = "Overkill Drum Mics", col=0 },
		{ type = "label",  title = "(Kick (2x), Snare(2x), HiHat, 3 Toms)", col=1, colspan = 1, align = "left"},
--		{ type = "checkbox", key = "stereo-overhead-mono", default = false,        title = "", col=2 },

		{ type = "checkbox", key = "check-overhead", default = false, title = "Drum Overheads", col=0 },
--		{ type = "entry",    key = "name-ldvox",   default = "Lead Vocal", title = "", col=1 },
		{ type = "checkbox", key = "stereo-overhead", default = false,        title = "", col=2 },

		{ type = "checkbox", key = "check-room", default = false, title = "Drum Room", col=0 },
--		{ type = "entry",    key = "name-ldvox",   default = "Lead Vocal", title = "", col=1 },
		{ type = "checkbox", key = "stereo-room", default = false,        title = "", col=2 },

		{ type = "checkbox", key = "check-bgvox", default = false, title = "Background Vocals (3x)", col=0 },
--		{ type = "entry",    key = "name-ldvox",   default = "Lead Vocal", title = "", col=1 },
		{ type = "checkbox", key = "stereo-bgvox", default = false,        title = "", col=2 },

		{ type = "hseparator", title="", col=0, colspan = 3},

		{ type = "checkbox", key = "group", default = false, title = "Group Track(s)?", col=0 },
	}

	--- check for available plugins
	-- gates
	local xt_eg = not ARDOUR.LuaAPI.new_plugin_info ("XT-EG Expander Gate (Mono)", ARDOUR.PluginType.LV2):isnil ()
	local xt_tg = not ARDOUR.LuaAPI.new_plugin_info ("XT-TG Tom Gate (Mono", ARDOUR.PluginType.LV2):isnil ()
	-- char
	local xt_tg = not ARDOUR.LuaAPI.new_plugin_info ("XT-BC Bass Character (Mono)", ARDOUR.PluginType.LV2):isnil ()
	local xt_vc = not ARDOUR.LuaAPI.new_plugin_info ("XT-VC Vocal Character (Mono)", ARDOUR.PluginType.LV2):isnil ()

	if (xt_eg and xt_tg) then
		table.insert (dialog_options,
		{ type = "checkbox", key = "gates", default = false, title = "Add Gate(s)?", col=0 }
		)
	end
	if (xt_tg and xt_vc) then
		table.insert (dialog_options,
		{ type = "checkbox", key = "char", default = false, title = "Add Character Plugin(s)?", col=0 }
		)
	end



	local dlg = LuaDialog.Dialog ("Template Setup", dialog_options)
	local rv = dlg:run()
	if (not rv) then
		return
	end

	-- helper function to reference processors
	function processor(t, s) --takes a track (t) and a string (s) as arguments
		local i = 0
		local proc = t:nth_processor(i)
			repeat
				if ( proc:display_name() == s ) then
					return proc
				else
					i = i + 1
				end
				proc = t:nth_processor(i)
			until proc:isnil()
		end

	--INSTANTIATING MIDI TRACKS IS TOO DAMN HARD
	function create_midi_track(name, chan_count) -- call this function with a name argument and output channel count
		Session:new_midi_track(ARDOUR.ChanCount(ARDOUR.DataType ("midi"), 1),  ARDOUR.ChanCount(ARDOUR.DataType ("audio"), chan_count), true, ARDOUR.PluginInfo(), nil, nil, 1, name, 1, ARDOUR.TrackMode.Normal)
		return true
	end

	function add_lv2_plugin (track, pluginname, position)
		local p = ARDOUR.LuaAPI.new_plugin(Session, pluginname, ARDOUR.PluginType.LV2, "")
		if not p:isnil () then
			track:add_processor_by_index(p, position, nil, true)
		end
	end


	local drum_group, bass_group, guitar_group, key_group, vox_group

	if rv['group'] then
		drum_group = Session:new_route_group("Drums")
		drum_group:set_rgba(0x425CADff)
		bass_group = Session:new_route_group("Bass")
		bass_group:set_rgba(0x1AE54Eff)
		guitar_group = Session:new_route_group("Guitars")
		guitar_group:set_rgba(0xB475CBff)
		key_group = Session:new_route_group("Keys")
		key_group:set_rgba(0xDA8032ff)
		vox_group = Session:new_route_group("Vox")
		vox_group:set_rgba(0xC54249ff)
	end

	local channel_count = 0

	if rv['check-basic-kit'] then
		local names = {"Kick", "Snare"}
		for i = 1, #names do
	    	local tl = Session:new_audio_track (1, 1, nil, 1, names[i],  insert_at, ARDOUR.TrackMode.Normal)
			for track in tl:iter() do
				--track:rec_enable_control ():set_value (1, PBD.GroupControlDisposition.NoGroup)
				if rv['group'] then drum_group:add(track) end
				if rv['gates'] then
					add_lv2_plugin (track, "XT-EG Expander Gate (Mono)", 0)
				end
			end
		end
		channel_count = channel_count + #names
	end

	if rv['check-full-kit'] then
		local names = {"Kick", "Snare", "Hi-Hat", "Hi-tom", "Mid-tom", "Fl-tom"}
		for i = 1, #names do
			local tl = Session:new_audio_track (1, 1, nil, 1, names[i],  insert_at, ARDOUR.TrackMode.Normal)
			for track in tl:iter() do
				--track:rec_enable_control ():set_value (1, PBD.GroupControlDisposition.NoGroup)
				if rv['group'] then drum_group:add(track) end
				if rv['gates'] then
					if string.find(track:name(), '-tom') then
						add_lv2_plugin (track, "XT-TG Tom Gate (Mono)", 0)
					else
						add_lv2_plugin (track, "XT-EG Expander Gate (Mono)", 0)
					end
				end
			end
		end
		channel_count = channel_count + #names
	end

	if rv['check-overkill-kit'] then
		local names = {"Kick In", "Kick Out", "Snare Top", "Snare Btm", "Hi-Hat", "Hi-tom", "Mid-tom", "Fl-tom"}
		for i = 1, #names do
			local tl = Session:new_audio_track (1, 1, nil, 1, names[i],  insert_at, ARDOUR.TrackMode.Normal)
			for track in tl:iter() do
				--track:rec_enable_control ():set_value (1, PBD.GroupControlDisposition.NoGroup)
				if rv['group'] then drum_group:add(track) end
				if rv['gates'] then
					if string.find(track:name(), '-tom') then
						add_lv2_plugin (track, "XT-TG Tom Gate (Mono)", 0)
					else
						add_lv2_plugin (track, "XT-EG Expander Gate (Mono)", 0)
					end
				end
			end
		end
		channel_count = channel_count + #names
	end

	if rv['check-overhead'] then
		local names = { "OH" }
		local ch = 1
		if rv["stereo-overhead"] then ch = 2 end --stereo
		for i = 1, #names do
			local tl = Session:new_audio_track (ch, ch, nil, 1, names[i],  insert_at, ARDOUR.TrackMode.Normal)
			for track in tl:iter() do
				--track:rec_enable_control ():set_value (1, PBD.GroupControlDisposition.NoGroup)
				if rv['group'] then drum_group:add(track) end
			end
		end
		channel_count = channel_count + ch
	end


	if rv['check-room'] then
		local names = { "Drum Room" }
		local ch = 1
		if rv["stereo-room"] then ch = 2 end --stereo
		for i = 1, #names do
			local tl = Session:new_audio_track (ch, ch, nil, 1, names[i],  insert_at, ARDOUR.TrackMode.Normal)
			for track in tl:iter() do
				--track:rec_enable_control ():set_value (1, PBD.GroupControlDisposition.NoGroup)
				if rv['group'] then drum_group:add(track) end
			end
		end
		channel_count = channel_count + ch
	end

	if rv['check-bass'] then
		local names = { rv["name-bass"] }
		local ch = 1
		if rv["stereo-bass"] then ch = 2 end --stereo
		for i = 1, #names do
			local tl = Session:new_audio_track (ch, ch, nil, 1, names[i],  insert_at, ARDOUR.TrackMode.Normal)
			for track in tl:iter() do
				--track:rec_enable_control ():set_value (1, PBD.GroupControlDisposition.NoGroup)
				if rv['group'] then bass_group:add(track) end
				if rv['char'] then
					add_lv2_plugin (track, "XT-BC Bass Character (Mono)", 0)
				end
			end
		end
		channel_count = channel_count + ch
	end

	if rv['check-electric-guitar'] then
		local names = { rv["name-electric-guitar"] }
		local ch = 1
		if rv["stereo-electric-guitar"] then ch = 2 end --stereo
		for i = 1, #names do
			local tl = Session:new_audio_track (ch, ch, nil, 1, names[i],  insert_at, ARDOUR.TrackMode.Normal)
			for track in tl:iter() do
				--track:rec_enable_control ():set_value (1, PBD.GroupControlDisposition.NoGroup)
				if rv['group'] then guitar_group:add(track) end
			end
		end
		channel_count = channel_count + ch
	end

	if rv['check-solo-guitar'] then
		local names = { rv["name-solo-guitar"] }
		local ch = 1
		if rv["stereo-solo-guitar"] then ch = 2 end --stereo
		for i = 1, #names do
			local tl = Session:new_audio_track (ch, ch, nil, 1, names[i],  insert_at, ARDOUR.TrackMode.Normal)
			for track in tl:iter() do
				--track:rec_enable_control ():set_value (1, PBD.GroupControlDisposition.NoGroup)
				if rv['group'] then guitar_group:add(track) end
			end
		end

		channel_count = channel_count + ch
	end

	if rv['check-acoustic-guitar'] then
		local names = { rv["name-acoustic-guitar"] }
		local ch = 1
		if rv["stereo-acoustic-guitar"] then ch = 2 end --stereo
		for i = 1, #names do
			local tl = Session:new_audio_track (ch, ch, nil, 1, names[i],  insert_at, ARDOUR.TrackMode.Normal)
			for track in tl:iter() do
				--track:rec_enable_control ():set_value (1, PBD.GroupControlDisposition.NoGroup)
				if rv['group'] then guitar_group:add(track) end
			end
		end

		channel_count = channel_count + ch
	end

	if rv['check-piano'] then
		local names = { rv["name-piano"] }
		local ch = 1
		if rv["stereo-piano"] then ch = 2 end --stereo
		for i = 1, #names do
			local tl = Session:new_audio_track (ch, ch, nil, 1, names[i],  insert_at, ARDOUR.TrackMode.Normal)
			for track in tl:iter() do
				--track:rec_enable_control ():set_value (1, PBD.GroupControlDisposition.NoGroup)
				if rv['group'] then key_group:add(track) end
			end
		end

		channel_count = channel_count + ch
	end

	if rv['check-electric-piano'] then
		local names = { rv["name-electric-piano"] }
		local ch = 1
		if rv["stereo-electric-piano"] then ch = 2 end --stereo
		for i = 1, #names do
			local tl = Session:new_audio_track (ch, ch, nil, 1, names[i],  insert_at, ARDOUR.TrackMode.Normal)
			for track in tl:iter() do
				--track:rec_enable_control ():set_value (1, PBD.GroupControlDisposition.NoGroup)
				if rv['group'] then key_group:add(track) end
			end
		end
		channel_count = channel_count + ch
	end

	if rv['check-organ'] then
		local names = { rv["name-organ"] }
		local ch = 1
		if rv["stereo-organ"] then ch = 2 end --stereo
		for i = 1, #names do
			local tl = Session:new_audio_track (ch, ch, nil, 1, names[i],  insert_at, ARDOUR.TrackMode.Normal)
			for track in tl:iter() do
				--track:rec_enable_control ():set_value (1, PBD.GroupControlDisposition.NoGroup)
				if rv['group'] then key_group:add(track) end
			end
		end
		channel_count = channel_count + ch
	end

	if rv['check-ldvox'] then
		local names = { rv["name-ldvox"] }
		local ch = 1
		if rv["stereo-ldvox"] then ch = 2 end --stereo
		for i = 1, #names do
			local tl = Session:new_audio_track ( ch, ch, nil, 1, names[i],  insert_at, ARDOUR.TrackMode.Normal)
			for track in tl:iter() do
				--track:rec_enable_control ():set_value (1, PBD.GroupControlDisposition.NoGroup)
				if rv['group'] then vox_group:add(track) end
				if rv['char']  then
					add_lv2_plugin (track, "XT-VC Vocal Character (Mono)", 0)
				end
			end
		end
		channel_count = channel_count + ch
	end

	if rv['check-bgvox'] then
		local names = { rv["name-bgvox"] }
		local ch = 1
		if rv["stereo-bgvox"] then ch = 2 end --stereo
		for i = 1, #names do
			local tl = Session:new_audio_track (ch, ch, nil, 1, names[i],  insert_at, ARDOUR.TrackMode.Normal)
			for track in tl:iter() do
				--track:rec_enable_control ():set_value (1, PBD.GroupControlDisposition.NoGroup)
				if rv['group'] then vox_group:add(track) end
			end
		end
		channel_count = channel_count + ch
	end

	--fit all tracks on the screen
	Editor:access_action("Editor","fit_all_tracks")

	Session:save_state("")

	-- determine the number of channels we can record
	local e = Session:engine()
	local _, t = e:get_backend_ports ("", ARDOUR.DataType("audio"), ARDOUR.PortFlags.IsOutput | ARDOUR.PortFlags.IsPhysical, C.StringVector())  -- from the engine's POV readable/capture ports are "outputs"
	local num_inputs = t[4]:size() -- table 't' holds argument references. t[4] is the C.StringVector (return value)

	if num_inputs < channel_count then
		-- warn the user if there are less physical inputs than created tracks
		LuaDialog.Message ("Session Creation",
			"Created more tracks than there are physical inputs on the soundcard",
			LuaDialog.MessageType.Info, LuaDialog.ButtonType.Close):run ()
	end

end end
